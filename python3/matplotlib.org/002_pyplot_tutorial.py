"""
matplotlib.pyplot是一个命令集合使matplotlib工作起来像MATLAB
pyplotAPI通常比面向对象的API缺一些灵活性
"""

#%%
# 使用pyplot创建一个可视化图表
import matplotlib
# 只给x的值, 将会自动生成相对的y轴的数据, 该数据与x是相等的, 但是是从0开始计数和记值
matplotlib.pyplot.plot([1, 2, 3, 4], label="只给了x值")
matplotlib.pyplot.plot([1, 2, 3, 4], [1, 4, 9, 18], label="给了x, y的值")
matplotlib.pyplot.ylabel("some numbers")
matplotlib.pyplot.legend()
matplotlib.pyplot.show()


#%%
import matplotlib.pyplot as plt
plt.plot([1, 2, 3, 4], [1, 4, 9, 16], "ro")  # color=red, marker=o
plt.axis([0, 6, 0, 20])   # [xmin, xmax, ymin, ymax]
plt.show()


#%%
# 所有的数据其实在matplotlib中的表现都是numpy.array
import numpy
import matplotlib.pyplot as plt

t = numpy.arange(0., 5., 0.2)
print(t)
# red dashes, blue squares, green triangles
plt.plot(t, t, "r--", t, t**2, "bs", t, t**3, 'g^')   # 一次性作画多个, 并指定样式
plt.show()


#%%
# 可以作画使用键-值方式表示的数据
import numpy
import matplotlib.pyplot as plt

data = {
    'a': numpy.arange(50),
    'c': numpy.random.randint(0, 50, 50),
    'd': numpy.random.randn(50)
}
data['b'] = data['a'] + 10 * numpy.random.randn(50)
data['d'] = numpy.abs(data['d']) * 100

# 指定Data参数, 这样可以使用data变量对应的关键字数据, 这里的abcd就分别对应了
plt.scatter('a', 'b', c='c', s='d', data=data)
plt.xlabel("entry a")
plt.ylabel("entry b")
plt.show()


#%%
# 使用categorical变量来作图
import numpy
import matplotlib.pyplot as plt

names = ["group_a", "group_b", "group_c"]
values = [1, 10, 100]

plt.figure(1, figsize=(9, 3))

plt.subplot(1, 3, 1)   # 子作图1行3列第1个
plt.bar(names, values)
plt.subplot(1, 3, 2)   # 子作图1行3列第2个
plt.scatter(names, values)
plt.subplot(1, 3, 3)   # 子作图1行3列第3个
plt.plot(names, values)
# 配置所有的标题
plt.suptitle("Categorical Plotting")
plt.show()


#%%
# 控制线段的性能
# 线段有众多的属性可以设置, 可以通过matplotlib.lines.Line2D查看
# plot 返回一个Line2D对象的list
lines = plt.plot(x1, y1, x2, y2)
# 使用setp命令, 可以同时设置多个在一个列表中的line对象属性
# use keyword args
plt.setp(lines, color='r', linewidth=2.0)
# or MATLAB style string value pairs
plt.setp(lines, 'color', 'r', 'linewidth', 2.0)


#%%
# 使用多个图层和坐标域
# 所有的plotting命令将会应用在当前得到当前的图层和坐标域中.
# 方法gca()返回当前的坐标域(matplotlib.axes.Axes 实例), gcf()返回当前的图层(matplotlib.figure.Figure 实例)
# 通常情况下, 这些都不用关心, 因为这些实现是由底层实现的
import numpy
import matplotlib.pyplot as plt

def fun(t):
    # 自然底数e的**-t 乘以 一个cos
    return numpy.exp(-t) * numpy.cos(2 * numpy.pi * t)

t1 = numpy.arange(0., 5., .1)
t2 = numpy.arange(0., 5., .02)

# 这里创建一个图层命令是可选的, 因为figure(1)将会被默认创建, 如果没有手动指定任何axes, subplot(111)将会被默认创建
plt.figure(1)   # 创建一个图层

plt.subplot(2, 1, 1)   # 2行1列第一个
plt.plot(t1, fun(t1), "bo", t2, fun(t2), "k")

plt.subplot(2, 1, 2)   # 2行1列第二个
plt.plot(t2, numpy.cos(2*numpy.pi*t2), "r--")
plt.show()


#%%
# axes() 命令允许自定义坐标域的位置与大小(0-1之间的小数)
# 通过figure()调用可以创建多个图层
import matplotlib.pyplot as plt

plt.figure(1)   # 创建使用1号图层
plt.subplot(2, 1, 1)
plt.plot([1, 2, 3])
plt.subplot(2, 1, 2)
plt.plot([4, 5, 6])

plt.figure(2)   # 创建使用2号图层
plt.plot([4, 5, 6])
plt.title("figure 2")

plt.figure(1)   # 在使用1号图层
plt.subplot(2, 1, 1)
plt.title("figure 1, Easy as 1, 2, 3")   # subplot 211 标题
plt.show()

# 可以使用clf()清理当前图层, 使用cla()清理当前坐标域
# 当使用了很多的图层的时候, 使用close() 清理这些图层退出时的占用内存, 关闭窗口和kill还不能释放, 只有调用close()


#%%
# 使用text
# text()命令可以用来添加任意位置的文本
import numpy
import matplotlib.pyplot as plt

mu, sigma = 100, 15
x = mu + sigma * numpy.random.randn(10000)

# 数据直方图
n, bins, patches = plt.hist(x, 50, density=1, facecolor="green", alpha=.75)

plt.xlabel("Smarts")
plt.ylabel("Probability")
plt.title("Histogram of IQ")
plt.text(60, .025, r'$\mu=100, \ \sigma=15$')   # 在坐标放上以某种格式放上文本
plt.axis([40, 160, 0, .03])   # [xMin, xMax, yMin, yMax]
plt.grid(True)   # 格栅
plt.show()

# text() 返回matplotlib.text.Text 实例, 也可以使用setp() 对其进行一些样式的设计
# 使用 TeX expression 来转义一些特殊的字符


#%%
# annotate() 方法提供了注解
import numpy as np
import matplotlib.pyplot as plt

ax = plt.subplot(111)   # 1行1列第一个的坐标域

t = np.arange(0.0, 5.0, 0.01)
s = np.cos(2*np.pi*t)
line = plt.plot(t, s, lw=2)   # Line2D对象的list

plt.annotate('local max', xy=(2, 1), xytext=(3, 1.5),   # xytext 表示文字的坐标
             arrowprops=dict(facecolor='black', shrink=0.05),   # 使用arrow, 并设置相应的样式
             )

plt.ylim(-2, 2)   # 设置当前坐标域的限定值
plt.show()


#%%
# Logarithmic and other nonlinear axes
# 对数和其他非线性的坐标域
# matplotlib.pyplot 不仅支持线性和scales的坐标域, 还支持对象户和logit scales
import numpy
import matplotlib.pyplot as plt
from matplotlib.ticker import NullFormatter   # 用于logit scales

numpy.random.seed(19680801)   # 固定种子, 让生成的随机数固定

y = numpy.random.normal(loc=0.5, scale=0.4, size=1000)
y = y[(y>0) & (y<1)]
y.sort()
x = numpy.arange(len(y))
print(y[:10])

# 创建图层
plt.figure(1)

# 线性
plt.subplot(2, 2, 1)   # 2行2列 a11
plt.plot(x, y)
plt.yscale("linear")
plt.title("linear")
plt.grid(True)

# 对数
plt.subplot(2, 2, 2)   # 2行2列 a12
plt.plot(x, y)
plt.yscale("log")
plt.title("log")
plt.grid(True)

# 对称对数 symmetric log
plt.subplot(2, 2, 3)   # 2行2列 a21
plt.plot(x, y-y.mean())
plt.yscale("symlog", linthreshy=0.01)
plt.title("symlog")
plt.grid(True)

# logit
plt.subplot(2, 2, 4)   # 2行2列 a22
plt.plot(x, y)
plt.yscale("logit")
plt.title("logit")
plt.grid(True)

# 将y轴的次要 tick labels格式化为空字符串 NullFormatter, 以避免使用太多标签造成阻碍.
plt.gca().yaxis.set_minor_formatter(NullFormatter())
# 适应subplot layout, 因为logit坐标可能会比通常的占用更多的space, 因为y-tick标签, 如: 1-10^{-3}
plt.subplots_adjust(top=0.92, bottom=0.08, left=0.10, right=0.95, hspace=0.25, wspace=0.35)

plt.show()
