# https://docs.sqlalchemy.org/en/rel_1_2/orm/tutorial.html

# Engine 是连接数据库和映射类的连接纽带, 其指定使用的数据库引擎.
# Declarative Base类是创建映射类的基类, 通过对其进行继承, 子类便成为了一个映射类.基类在全应用中, 最好只出现一个.
# Session类是与数据库进行对话的会话类, 通过与Engine的绑定, 在其中完成对数据库的基本操作.


### NOTE: Connection ###
from sqlalchemy import create_engine

# echo 参数, 使用了内建的logging库, 当为True的时候, 将会在终端打印详生成的SQL语句, 为False将不会打印
# create_engine() 是一个快捷方式, 返回一个Engine对象, 代表了与不同数据库链接的接口集合.
# Engine和数据库建立了一个lazy connection,  当使用Engine.execute()或Engine.connect()时, Engine对象与数据库将建立一个真的DBAPI链接, 这样可以之后使用SQL语句.
engine = create_engine('sqlite:///:memory:', echo=True)


### NOTE: Declare a Mapping ###
# 当使用ORM的时候, 配置的过程开始于描述一个数据库, 然后自定义一些类与其建立映射.
# 在现代的SQLAlchemy中, 这两个进程通常是一起执行的, 使用一个可以创建包含指令去描述一个真实的数据库表并与其映射的类, 该系统叫做Declarative
# 被映射的类使用的Declarative系统根据一个维持一个类目录和关联表的基类被定义. 被称为declarative Base class
# 我们的应用通常只有一个declarative基础的实例在一个公用导入模板中. 使用declaretive_base()来创建它.
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

# 使用declarative Base class 来创建一个User表

from sqlalchemy import Column, Integer, String, Sequence

class User(Base):
    __tablename__ = "users"
    id = Column(Integer, Sequence("user_id_seq"), primary_key=True)   # 在Firebird和Oracle中需要加入序列
    name = Column(String(64))
    fullname = Column(String(128))
    nickname = Column(String(64))

    def __repr__(self):
        return "<User %s name: %s, fullname: %s, nickname: %s>" \
                % (self.id, self.name, self.fullname, self.nickname)

# 一个使用Declarative的子类至少要有__tablename__和一个Column()是主键.
# SQLAlchemy从不对类引用的表做任何假设, 包括它没有名称，数据类型或约束的内置事务.
# 但这并不意味着需要样板; 相反, 我们鼓励您使用辅助函数和mixin类创建自己的自动事务.
# 当类的结构确定后, Declarative将会使用一个被叫做descriptors的Python存取替换所有的Column对象, 这个进程叫做 instrumentation.


### NOTE: Create a Schema ###
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
print(Base.metadata.create_all(engine))   # 对连接引擎使用映射, 创建数据库


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


### NOTE: Adding and Updating Objects ###
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


### NOTE: Rolling Back ###
# 当Session在定义中工作时, 可以使用roll back改变所做的工作.
ed_user.name = "Edwardo"
fake_user = User(name="fakeuser", fullname="Invalid", nickname="12345")   # 添加一个用于实验的用户
session.add(fake_user)
search_result = session.query(User).filter(User.name.in_(["Edwardo", "fakeuser"])).all()
print(search_result)   # 新的更改和用户被缓冲进了事务缓冲区
# 进行回退
session.rollback()
print(fake_user in session)   # 回退后, 是否fake_user还在会话中
search_result = session.query(User).filter(User.name.in_(["ed", "fakeuser"])).all()
print(search_result)   # 再次查询是否存在相关更改和用户, 将会只显示更改前的Ed_user


### NOTE: Querying ###
# 使用Session中的query()方法创建Query对象. 这个方法使用任意数量的参数来实现任意的类和instrumented类的描述的组合.
for instance in session.query(User).order_by(User.id):
    print(instance.name, instance.fullname)

# Query也可以接受ORM-instrumented描述作为参数. 任何时候当众多类实体或基于列的实体被作为参数传递给query()方法, 结果将会是一个tuple对象.
for name, fullname in session.query(User.name, User.fullname):
    print(name, fullname)
# 由Query对象返回的tuples是named tuples, 由KeyedTuple类提供支持, 并且可以向Python序列对象一样处理.
# 名称与属性的属性名称以及类名称相同.
for row in session.query(User, User.name).all():
    print(row.User, row.name)

# 可以使用由ColumnElement驱动的label()结构表达式对象指定单个列的名字, 如同sql中的as, 就和其他有映射的类参数一样
for row in session.query(User.name.label("name_label")).all():
    print(row.name_label)

# 使用aliased()可以赋予一个完整的映射对象别名.
from sqlalchemy.orm import aliased
user_alias = aliased(User, name="user_alias")
for row in session.query(user_alias, user_alias.name).all():
    print(row.user_alias)

# 使用Query对象的基础操作, 如LIMIT, OFFSET等, 这些大多数可便利的使用Python数组切片和一般与ORDER BY结合的方式实现.
for u in session.query(User).order_by(User.id)[1:3]:
    print(u)
# filter结果, 可以使用根据关键字参数来完成的filter_by()方法来实现.
for name, in session.query(User.name).filter_by(fullname="Ed Jones"):
    print(name)
# filter结果也可以使用filter()方法, 其使用更领货的SQL表达式. 可以在类等级上使用常规的Python操作于映射类.
for name, in session.query(User.name).filter(User.fullname=="Ed Jones"):
    print(name)

# Query对象是一个fully generative, 这意味着大多数方法的调用都将会返回一个新的Query对象, 在这之上可以添加其他标准.
for user in session.query(User).filter(User.name=="ed").filter(User.fullname=="Ed Jones"):
    print(user)

### common Filter Operation ###
# 常见的filter()方法操作
query = session.query(User)

query.filter(User.name=="ed")   # 相等
query.filter(User.name!="ed")   # 不相等
query.filter(User.name.like("%ed%"))   # like
query.filter(User.name.ilike("%ed%"))  # 忽略大小写的like
query.filter(User.name.in_(["ed", "wendy", "jack"]))    # in
query.filter(User.name.in_(session.query(User.name).filter(User.name.like("%ed%"))))   # 使用in的联合查询
query.filter(~User.name.in_(["ed", "wendy", "jack"]))   # not in
query.filter(User.name==None)   # is null
query.filter(User.name.is_(None))   # is null
query.filter(User.name!=None)   # is not null
query.filter(User.name.isnot(None))   # is not null
from sqlalchemy import and_
query.filter(and_(User.name=="ed"), User.fullname=="Ed Jones")   # 使用特殊函数实现的and
query.filter(User.name=="ed", User.fullname=="Ed Jones")   # 直接通过多参数实现的and
query.filter(User.name=="ed").filter(User.fullname=="Ed Jones")   # 通过链式查询实现的and
from sqlalchemy import or_
query.filter(or_(User.name=="ed", User.name=="wendy"))   # 使用特殊函数实现的or
query.filter(User.name.match("wendy"))   # match, 其使用数据库特定的MATCH或者CONTINS功能, 因各数据库平台而有差异

### Returning Lists and Scalars ###
# 返回列表和标量
# 许多在Query对象上的方法立刻发出SQL并返回从连接的数据库查询的值.
query = session.query(User).filter(User.name.like("%ed%")).order_by(User.id)

# all() 返回一个list
print(query.all())

# first() 返回一个值
print(query.first())

# one() 获取所有的行, 如果结果存在多行(即多个结果)或没有结果, 将会报错
# print(query.one())

# one_or_none() 和one()类似, 但是当没有结果的时候, 不会报错
# scalar() 调用one(), 成功时返回第每行的第一列

### Using Textual SQL ###
# 使用文本化的SQL
# text() 通过使用text()构建字符串形式的查询, 其可以被灵活的使用在Query对象上, 这种形式被大多数Query方法接受.
from sqlalchemy import text

for user in session.query(User).filter(text("id<5")).order_by(text("id")).all():
    print(user.name)

# params() 可以使用基于字符串的SQL，使用冒号指定绑定参数。
search_result = session.query(User).filter(text("id<:value and name=:name")).params(value=224, name="fred").order_by(User.id).one()
print(search_result)

# from_statement() 可以使用基于字符串的完整的SQL查询语句, 将text()构造的字符串对象传递给from_statement()就可以.
# 不需要额外指定, SQL字符串中使用的列名都集基于映射模型中的名字.
search_result = session.query(User).from_statement(text("SELECT * FROM users where name=:name")).params(name="ed").all()
print(search_result)

# 当在处理复杂语句的时候对于简单的事例工作通过名字匹配列可能变的不便利, 尤其是其包括复杂的列名或使用匿名的不好匹配特殊名字的ORM构成时.
# 另外的, 当处理结果行有可以在当前的映射列上直接输入行为是必要的.
# 在这样的情景下, text()构成允许以字符串形式的SQL连接对应的Core或ORM-mapped列表达式.
# 可以通过传递列表达式作为位置参数给TextClause.columns()来实现这个.
stmt = text("SELECT name, id, fullname, nickname FROM users where name=:name")
stmt = stmt.columns(User.name, User.id, User.fullname, User.nickname)
search_result = session.query(User).from_statement(stmt).params(name="ed").all()
print(search_result)

# The TextClause.columns() method now accepts column expressions which will be matched positionally to a plain text SQL result set, 
# eliminating the need for column names to match or even be unique in the SQL statement.

# 当从text()构造中选择时，查询仍然可以指定要返回哪些列和实体; 也可以单独请求这些列，而不是query(User)，就像在任何其他情况下一样
stmt = text("SELECT name, id FROM users where name=:name")
stmt = stmt.columns(User.name, User.id)
search_result = session.query(User.id, User.name).from_statement(stmt).params(name="ed").all()

### Count ###
# 计数
# Query对象的计数方法count()
count_num = session.query(User).filter(User.name.like("%ed")).count()
print(count_num)

# 需要独立使用count功能的时候可以从func中取引入, 可以单独对某一列进行统计
from  sqlalchemy import func

count_num = session.query(func.count(User.name), User.name).group_by(User.name).all()
print(count_num)   # 统计每个名字有多少重名的

# SELECT count(*) FROM table;
count_num = session.query(func.count("*")).select_from(User).scalar()
print(count_num)
# 如果直接指定计数主键, 以上select_from可以被省略
count_num = session.query(func.count(User.id)).scalar()
print(count_num)


### NOTE: Building a Relationship ###
# 创建一个和User相关联的邮件地址映射表, 这里将建立一个一对多的关系, User 1 -- Address 多
from sqlalchemy import ForeignKey
from sqlalchemy.orm import relationship

class Address(Base):
    __tablename__ = "addresses"
    id = Column(Integer, primary_key=True)
    email_address = Column(String, nullable=False)
    user_id = Column(Integer, ForeignKey("users.id"))
    
    user = relationship("User", back_populates="addresses")

    def __repr__(self):
        return "<Address email_address: %s; user: %s>" % (self.email_address, self.user.name) 


User.addresses = relationship("Address", order_by=Address.id, back_populates="user")

# 上面的类介绍了ForeignKey构造，它是一个应用于Column的指令，表明此列中的值应该被constrained(限制), 其值代表了远端相同名字的列.
# 这在关系型数据库中是一个核心功能, 并作为一种粘合剂将相反的没有连接的表集合相互交叠形成丰富的联系.
# ForeignKey表明在addresses.user_id列中的值应该也包含在users.id列中. 即是一个主键.

# orm.relationship()方法告诉ORM使用Address.user属性将Address类和User类相互连接.
# 在Address中的relationship()使用外键关联了两个表, 决定连接的性质, 定义了Address.user是一个many to one的关系.
# 另一个relationship()在User.address中.
# 在两个relationship()指令中, 参数relationship.back_populates被分配附加的属性名给该列, 通过这个, 每一个relationship()可以做出与反向表达的相同关系的智能决策.
# 在另一方面Address.user引用一个User的实例, 同时User.address页应用了一个Address实例的列表.
# 也有个和relationship.back_populates相似的参数, 是relationship.backref, 前者对后者做了一些优化.

# FOREIGN KEY 约束在大多数关系型数据库汇总只能连接到一个主键列或一个UNIQUE约束列
# FOREIGN KEY 约束引用了多个主键列并且本身也有多列, 被叫做复合外键
# FOREIGN KEY 列可以根据自己引用的列或行的变动而自动更新. 这被叫为CASCADE referential action(级联操作), 并且这是由关系型数据库的内建函数完成.
# FOREIGN KEY 可以引用自己所在的表. 这叫做自关联

# 创建addresses表, 将跳过存在的表而创建没有的
Base.metadata.create_all(engine)


### NOTE: Working with Related Objects ###
jack = User(name="jack", fullname="Jack Bean", nickname="gjffdd")
print(jack.addresses)   # 默认返回是一个Python list对象

# 可以自由的将Address对象加入User对象
jack.addresses = [
    Address(email_address="jack@google.com"),
    Address(email_address="j25@yahoo.com")
]

# 当使用双向关联, 元素自动添加并变得以其定义的顺序排列的可见.
print(jack.addresses)
session.add(jack)
session.commit()

# 当连接到addresses集合, SQL语句将会立刻发出. 这就是lazy loading关系的一个例子. 
# addresses集合当前被载入并表现的像一个有序列表. 
jack_search = session.query(User).filter_by(name="jack").one()
print(jack_search, jack_search.addresses)

#　REVIEW: https://docs.sqlalchemy.org/en/rel_1_2/glossary.html#term-lazy-loading

# 多对多的关系
# from sqlalchemy import Table

# class Project(Base):
#     __tablename__ = 'project'

#     id = Column(Integer, primary_key=True)
#     name = Column(String(30))


# class Employee(Base):
#     __tablename__ = 'employee'

#     id = Column(Integer, primary_key=True)
#     name = Column(String(30))

#     projects = relationship(
#         "Project",
#         secondary=Table('employee_project', Base.metadata,
#                     Column("employee_id", Integer, ForeignKey('employee.id'),
#                                 primary_key=True),
#                     Column("project_id", Integer, ForeignKey('project.id'),
#                                 primary_key=True)
#                 ),
#         backref="employees"
#     )


# CREATE TABLE employee (
#     id INTEGER PRIMARY KEY,
#     name VARCHAR(30)
# )

# CREATE TABLE project (
#     id INTEGER PRIMARY KEY,
#     name VARCHAR(30)
# )

# CREATE TABLE employee_project (
#     employee_id INTEGER PRIMARY KEY,
#     project_id INTEGER PRIMARY KEY,
#     FOREIGN KEY employee_id REFERENCES employee(id),
#     FOREIGN KEY project_id REFERENCES project(id)
# )


### NOTE: Querying with Joins ###
# 联合查询
# 可以在query中指定连接显示的列, query就相当于selec后面到from中的那一串
# 构建一个简单的隐式的join在User和Address之间, 可以使用Query.filter()连接两者的列.
for u, a in session.query(User, Address).\
                         filter(User.id==Address.user_id).\
                         filter(Address.email_address.ilike("%jack%")).all():
    print(u, a)


# 使用Query.join() 显示的构建联合查询
search_result = session.query(User).join(Address).\
                                filter(Address.email_address.ilike("%jack%")).all()
print(search_result)

# Query.join()方法知道如何去join User和Address表, 因为只用一个外键连接User和Address. 
# 如果没有外键(foreign key), 或者是多个外键, Query.join(), 可以使用如下, 直接在join中指定.
query = session.query(User)
query.join(Address, User.id==Address.user_id)   # 显示的指定
query.join(User.addresses)                      # 从左到右指定关系
query.join(Address, User.addresses)             # 显示的指定
query.join("addresses")                         # 使用字符串显示的指定

# 使用outer join, 使用Query.outerjoin()方法
query.outerjoin(User.addresses)   # 左外部连接

# 如果有多个实体, Query将如何选择?
# Query.join()方法一般都会从在实例列表中最左边的项进行join, 当 ON语句被省略, 或 ON语句是一个纯SQL表达式.
# 想要控制第一个join的实例, 使用Query.select_from()方法
query = session.query(User, Address).select_from(Address).join(User)

# Using Aliases # 
# 使用别名
# 在跨多个表进行查询时，如果需要多次引用同一个表，则SQL通常要求使用其他名称对该表进行别名，以便可以将该表与该表的其他实例区分开来。
from sqlalchemy.orm import aliased
adalias1 = aliased(Address)
adalias2 = aliased(Address)
for username, email1, email2 in \
    session.query(User.name, adalias1.email_address, adalias2.email_address).\
    join(adalias1, User.addresses).\
    join(adalias2, User.addresses).\
    filter(adalias1.email_address=="jack@google.com").\
    filter(adalias2.email_address=="j25@yahoo.com"):
    print(username, email1, email2)

# query中指定了连接的列

# Using Subqueries # 
# 使用子查询
# Query对象适用于生成可作为子查询的语句. 
# SELECT user.*, adr_count.address_count FROM users
# LEFT OUTER JOIN 
#    (SELECT user_id, count(*) AS address_count FROM address 
#        GROUP By user_id) AS adr_count
# ON users.id = adr_count.user.id;
# 使用Query, 从内到外创建一个语句. statement 访问返回一个代表由通常的Query产生的Select()构造实例的SQL表达式
from sqlalchemy import func
stmt = session.query(Address.user_id, func.count("*").\
    label("address_count")).\
    group_by(Address.user_id).subquery()
# func关键字产生SQL方法, Query对象上subquery()方法生成一个SQL表达式构造, 表示嵌入在别名中的SELECT语句(实际上其是query().statement.alias()的缩写)
# 当有了一个语句, 其行为和Table结构相似, 就像一个users表的实例对象.
for u, count in session.query(User, stmt.c.address_count).\
    outerjoin(stmt, User.id==stmt.c.user_id).order_by(User.id):
    print(u, count)

# Selecting Entities from Subqueries #
# 子查询中的selecting实体
# 在上面的例子中, 只是选择了一个从子查询中包含一列的结果. 如果想要子查询映射到一个实体呢?
# 可以使用aliased()来关联一个从类映射到子查询的"alias".
stmt = session.query(Address).filter(Address.email_address!="j25@yahoo.com").subquery()
adalias = aliased(Address, alias=stmt)
for user, address in session.query(User, adalias).\
    join(adalias, User.addresses):
    print(user, address, sep="\n")

# Using EXISTS # 
# 使用EXISTS语句
# 在SQL中的EXISTS关键字是一个布尔操作符, 当给予的表达式包含行时, 将会返回True.
# 其可能会被用在许多的场景中, 例如joins语句中, 查找列是否在关联的表中有值.
from sqlalchemy.sql import exists
stmt = exists().where(Address.user_id==User.id)
for name, in session.query(User.name).filter(stmt):
    print(name)

# 一些在Query对象中的操作会自动的使用EXISTS. 例如 any(), has()
for name, in session.query(User.name).\
    filter(User.addresses.any()):
    print(name)

for name, in session.query(User.name).\
    filter(User.addresses.any(Address.email_address.like("%google%"))):
    print(name)

isHas = session.query(Address).filter(~Address.user.has(User.name=="jack")).all()   # address中的user是否有不是用户jack的数据
print(isHas)

# Common Relationship Operators #
query = session.query(Address)
user_object = session.query(User).filter(User.name == "jack")
address_object = session.query(Address).filter(Address.user.name == "jack").first()
# __eq__()   多对一 相等比较
query.filter(Address.user == user_object)
# __ne__()   多对一 不相等比较
query.filter(Address.user != user_object)
# IS NULL   多对一比较, 同样使用 __eq__()
query.filter(Address.user == None)
# contains()   一对多集合
query.filter(User.address.contains(address_object))
# any()   用于集合
query.filter(User.addresses.any(Address.email_address == "bar"))
query.filter(User.addresses.any(email_address = "bar"))   # 使用关键字参数
# has()   用于范围查询
query.filter(Address.user.has(name="ed"))
# Query.with_parent() 用于关联
session.query(Address).with_parent(user_object, "addresses")



### NOTE: Eager Loading ###
# 在访问User.addresses集合并发出SQL时, 当时说明了一个延迟加载操作.
# 如果想要减少查询的次数, 可以在查询操作中使用一个eager loading.
# SQLAlchemy提供了三种不同类型的eager loading. 其中两个是自动的, 另一个涉及自定义标准.
# 所有的这三个通常需要通过查询选项的方法, 其可以提供额外的内容到Query, 可定义各种属性的载入通过 Query.options()方法

# Subquery Load # 
# 在这个示例中, 想要表明User.addresses应该load eagerly.
# 一个对于加载一个对象集合以及他们相关联的集合的好的选择是orm.subqueryload()选项, 其发出二次通过已被加载结果全加载集合的SELECT语句.
# "subquery"的名字来自于SELECT语句直接通过Query 再使用, 作为一个子查询被嵌套进一个针对关联表SELECT中的构造
from sqlalchemy.orm import subqueryload
jack = session.query(User).options(subqueryload(User.addresses)).filter_by(name="jack").one()
print(jack)
# 当subqueryload 用于关联限制比如Query.first(), Query.limit()或Query.offset()为了保证正确的结果, 应该同样包含Query.order_by()在一个unique列中

# Joined Load #

#　TODO:
