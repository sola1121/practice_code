"""
matplotlib是分级化的, 其下层最顶层就是pyplot, 这是一个高级的对象的封装
调用他会自动的创建figure(图层), Axes(坐标域), axis(坐标轴)等
backends概念, 使用什么样的终端或者说什么样的软体来输出图表表现
涉及是否使用交互的方式输出或使用非交互的形式将内容输出
性能优化, matplotlib.rcParams["path.simplify"]参数的使用
matplotlib.pyplot.plot(markevery=int_object) 对于Line2D对象,标价
"""

#%%
import matplotlib
import numpy

# 使用pyplot创建一个图层
fig = matplotlib.pyplot.figure()  # 将会创建一个空图层
fig.suptitle("No axes on this figure")   # 加个标题
fig, ax_lst = matplotlib.pyplot.subplots(2, 2)   # 图层具有2 * 2 的格栅grid


#%%
# 所有的plotting方法都期望输入的对象是一个numpy.array或numpy.ma.masked_array对象
import numpy
b = numpy.matrix([[1,2],[3,4]])
b_asarray = numpy.asarray(b)
print(b)
print(b_asarray)


#%%
import numpy
import matplotlib

x = numpy.linspace(0, 2, 100)  # 在0~2内生成均等的有100个元素的数组
print(x)

# 第一个调用的pyplot会自动的创建需要的figure(图层)和坐标域(axes)
matplotlib.pyplot.plot(x, x, label="linear")
# 接下来的将会使用已经创建的图层和坐标域
matplotlib.pyplot.plot(x, x**2, label="quadratic")
matplotlib.pyplot.plot(x, x**3, label="cubic")

matplotlib.pyplot.title("Simple Plot")

matplotlib.pyplot.legend()

matplotlib.pyplot.show()


#%%
import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10, 0.2)   # (start, end, step, dtype=None), 生成范围内数据
y = np.sin(x)

fig, ax = plt.subplots()   # Create a figure and a set of subplots.
ax.plot(x, y, label="sin")
plt.legend()
plt.show()


#%%
import numpy as np
import matplotlib
import matplotlib.pyplot as plt

matplotlib.use("Qt5Agg")

def my_plotter(ax, data1, data2, param_dict):
    # 在坐标域axes中作画
    out = ax.plot(data1, data2, **param_dict)
    return out

data1, data2, data3, data4 = np.random.randn(4, 100)
fig, (ax1, ax2) = plt.subplots(1, 2)
my_plotter(ax1, data1, data2, {"marker": "x"})
my_plotter(ax2, data3, data4, {"marker": "o"})
plt.show()


#%%
import matplotlib.pyplot as plt
# 开启交互
plt.ion()
plt.plot([1.6, 2.7])

#%%
import matplotlib.pyplot as plt
# 关闭交互
plt.ioff()
plt.plot([1.6, 2.7])
plt.show()


#%%
import numpy
import matplotlib

matplotlib.pyplot.ioff()   # 关闭了交互, 将会依次在界面上画出三条线, 挨个画出
# matplotlib.pyplot.ion()   # 开启交互, 将会在同一图层上画出三条线, 即一次画出
for i in range(3):
    matplotlib.pyplot.plot(numpy.random.rand(10), markevery=10)
    matplotlib.pyplot.show()


#%%
import numpy
import matplotlib

# 使用line segment来提升性能

y = numpy.random.rand(100000)
y[50000:] *= 2
y[numpy.logspace(1, numpy.log10(50000), 400).astype(int)] = -1
matplotlib.rcParams["path.simplify"] = True   # whether or not line segments are simplified at all.

matplotlib.rcParams["path.simplify_threshold"] = 0.0   #  how much line segments are simplified
matplotlib.pyplot.plot(y)
matplotlib.pyplot.show()

matplotlib.rcParams["path.simplify_threshold"] = 1.0   # 限制越高, 结果产生的越快
matplotlib.pyplot.plot(y)
matplotlib.pyplot.show()


#%%
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
mpl.rcParams['path.simplify_threshold'] = 1.0

# Setup, and create the data to plot
y = np.random.rand(100000)
y[50000:] *= 2
y[np.logspace(1,np.log10(50000), 400).astype(int)] = -1
mpl.rcParams['path.simplify'] = True

mpl.rcParams['agg.path.chunksize'] = 0
plt.plot(y)
plt.show()

mpl.rcParams['agg.path.chunksize'] = 10000
plt.plot(y)
plt.show()


# 通过使用fast来提速
import matplotlib.style as mplstyle
mplstyle.use('fast')

# fast style 自动的在simplify_threshold和chunksize上使用
# 其他的style
mplstyle.use(['dark_background', 'ggplot', 'fast'])