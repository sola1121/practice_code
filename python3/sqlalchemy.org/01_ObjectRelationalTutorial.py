# https://docs.sqlalchemy.org/en/rel_1_2/orm/tutorial.html

### Connection ###
from sqlalchemy import create_engine

# echo 参数, 使用了内建的logging库, 当为True的时候, 将会在终端打印详生成的SQL语句, 为False将不会打印
# create_engine() 是一个快捷方式, 返回一个Engine对象, 代表了与不同数据库链接的接口集合.
# Engine和数据库建立了一个lazy connection,  当使用Engine.execute()或Engine.connect()时, Engine对象与数据库将建立一个真的DBAPI链接, 这样可以之后使用SQL语句.
engine = create_engine('sqlite:///:memory:', echo=True)


### Declare a Mapping ###
# 当使用ORM的时候, 配置的过程开始于描述一个数据库, 然后自定义一些类与其建立映射.
# 在现代的SQLAlchemy中, 这两个进程通常是一起执行的, 使用一个可以创建包含指令去描述一个真实的数据库表并与其映射的类, 该系统叫做Declarative
# 被映射的类使用的Declarative系统根据一个维持一个类目录和关联表的基类被定义. 被称为declarative base class
# 我们的应用通常只有一个declarative基础的实例在一个公用导入模板中. 使用declaretive_base()来创建它.
from sqlalchemy.ext.declarative import declarative_base

base = declarative_base()

# 使用declarative base class 来创建一个User表

from sqlalchemy import Column, Integer, String, Sequence

class User(base):
    __tablename__ = "users"
    id = Column(Integer, Sequence("user_id_seq"), primary_key=True)   # 在Firebird和Oracle中需要加入序列
    name = Column(String(64))
    fullname = Column(String(128))
    nickname = Column(String(64))

    def __repr__(self):
        return "<User %s name: %s, fullname: %s, nickname: %s>" \
                % (self.id, self.name, self.fullname, self.nickname)

# 一个使用Declarative的子类至少要有__tablename__和一个Column()是主键.
# SQLAlchemy从不对类引用的表做任何假设, 包括它没有名称，数据类型或约束的内置约定.
# 但这并不意味着需要样板; 相反, 我们鼓励您使用辅助函数和mixin类创建自己的自动约定.
# 当类的结构确定后, Declarative将会使用一个被叫做descriptors的Python存取替换所有的Column对象, 这个进程叫做 instrumentation.


### Create a Schema ###
# 通过Declarative System使用相应命令来构建的User类, 其中的这些描述被叫做 table metadata. 
# 被SQLAlchemy用来代表一个指定的表的信息称为Table对象. 可以从相应表对象的__table__属性中看到定义.
print(User.__table__)

# 当我们声明了一个类, 当这个类定义完成, Declarative 将使用Python元类来补充额外的活动.
# 在这个阶段, 将会更具我们的指定创建一个Table对象, 并通过构建一个Mapper对象与其连接.
# Mapper对象是一个幕后对象, 通常我们都不用显式的处理他. 其中提供了大量的关于我们映射的信息.
# Table对象是大集合MetaData的一个成员. 当使用Declarative的时候, 这个对象是可以通过declarative base类中.meatadata属性获得的.
# MetaData是一个包含了能够向数据库发出一组有限的schema generation命令的注册处.
# 当我们的SQLite数据库没有存在users表的时候, 可以使用MetadData来向数据库发出CREATE TABLE命令来创建没有存在的数据库表.
# 可以执行MetaData.create_all()方法, 传入我们Engine作为数据库链接的来源. 首先将会检查users表的存在, 并在之后产生实际的CREATE TABLE指令.
print(base.metadata.create_all(engine))   # 对连接引擎使用映射, 创建数据库


### Create an Instance of the Mapped Class ###
ed_user = User(name='ed', fullname='Ed Jones', nickname='edsnickname')
print(ed_user)   # 在这里可以看到id为None

# 我们使用Declarative系统定义的User类已经提供了一个构造函数（例如__init __（）方法），它自动接受与我们映射的列匹配的关键字名称。
# 我们可以自由地在我们的类上定义任何我们喜欢的显式__init __（）方法，它将覆盖Declarative提供的默认方法。

# 不同于Python对错误属性的处理, 他没有raise AttributeError. 
# SQLAlchemy的instrumentation通常在第一次连接时提供默认的值给列映射属性. 
# 对于那些我们事实上分配了值的属性, instrumentation system将追踪那些分配, 用来在最终向数据库发送INSERT语句.


### Creating Session ###
# session三状态 transient, pending, persistent. 临时的, 待定的, 永久的.
# 处理ORM与数据库之间交流的是Session. 在第一次创建应用时, 在统一层面上create_engin发生时,就定义了一个Session类, 其将会作为一个工厂函数服务于新的session对象.

from sqlalchemy.orm import sessionmaker
Session = sessionmaker(bind=engine)

# 当还没有定义Engin对象的时候, 可以先创建一个会话对象, 然后在定义了Engine对象后在配置
Session = sessionmaker()
Session.configure(bind=engine)

# 当有和后端数据库进行相应的交流的时候, 可以实例化配置好的Session对象
session = Session()
# 当实例化的session对象第一次使用后, 其将会连接到一个由Engine对象维护的内存池中, 直到commit或者close会话.


### Adding and Updating Objects ###
# 将ed_user对象加入session
ed_user = User(name="ed", fullname="Ed Jones", nickname="edsnickname")
session.add(ed_user)   # ed_user 实例进入pending状态, 还没有真正的进入数据库
# Session将使用被称为flush的过程发出SQL以便在需要时尽快保留Ed Jsons.
# 当对Ed Jsons进行查询的时候, pending状态的信息将会首先被flushed, 并查询在这之后被立刻执行.

# 创建一个新的载入了User的Query对象, 使用查询可以找到Ed Jsons的字段
the_user = session.query(User).filter_by(name="ed").first()
print(the_user, ed_user is the_user)

# 这里起作用的ORM概念是identity map和保证所有在一个Session操作中的一个特殊行操作都在同一个数据集中.
# 当一个有特定主键的对象存在于Session, 所有的在Session中的SQL查询对这个特殊的主键将总是返回一样的Python对象.
# 并也会raise一个错误如果尝试在会话中放置具有相同主键的第二个已经持久化的对象

# 使用add_all()添加更多的User对象
session.add_all([
    User(name='wendy', fullname='Wendy Williams', nickname='windy'),
    User(name='mary', fullname='Mary Contrary', nickname='mary'),
    User(name='fred', fullname='Fred Flintstone', nickname='freddy')
])

# 可以在这个过程中更改User对象的内容
ed_user.nickname = "eddie"
# 当内容被修改了后, 将会引起session的关注, 可以使用session.dirty查看
print(session.dirty)
# 新添加的使用session.new查看
print(session.new)

# 当想要提交这些改变到数据库的时候, 可以通过commit()方法, session对象将会发出UPDATE语句对于修改的字段, INSERT语句对于新增的字段.
session.commit()
# 会话引用的连接资源现在返回到连接池.
# 接下来session的操作将会发起一连串的new指令, 当再被需要时这将会在一次获得连接资源.

print(ed_user.id)   # 数据库将会自动分配id, 这些都是现代数据库的特性.
# 因为commit()后发起了新的通路, 所有的行将会重新载入到访问中.
# SQLAlchemy默认将会自动从先前的通路中刷新数据当一个新的通路开启了连接, 所以大多数最近的状态是可用的.
# 重新载入的等级可以通过Session配置.


### Rolling Back ###
# 当Session在定义中工作时, 可以使用roll back改变所做的工作.
ed_user.name = "Edwardo"
fake_user = User(name="fakeuser", fullname="Invalid", nickname="12345")   # 添加一个用于实验的用户
session.add(fake_user)
search_result = session.query(User).filter(User.name.in_(["Edwardo", "fakeuser"])).all()
print(search_result)

