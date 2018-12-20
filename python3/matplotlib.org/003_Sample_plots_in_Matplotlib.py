"""
创建有标签(label)的线段使用 plot()
    matplotlib.pyplot.plot(*args, scalex=True, scaley=True, data=None, **kwargs)
    -> A list of Line2D objects representing the plotted data.

创建多个坐标域(axes)使用 subplot()
    matplotlib.pyplot.subplot(*args, **kwargs)
    -> axes : an axes.SubplotBase subclass of Axes (or a subclass of Axes)
       The axes of the subplot. The returned axes base class depends on the projection used. It is Axes if rectilinear projection are used and projections.polar.PolarAxes if polar projection are used. The returned axes is then a subplot subclass of the base class.

显示图片可以使用 imshow()
    matplotlib.pyplot.imshow(X, cmap=None, norm=None, aspect=None, interpolation=None, alpha=None, vmin=None, vmax=None, origin=None, extent=None, shape=None, filternorm=1, filterrad=4.0, imlim=None, resample=None, url=None, *, data=None, **kwargs)[source]
    -> AxesImage

制作二维数组的颜色表示的pseudocolor plot(一个flase-color图)  pcolormesh()
    matplotlib.pyplot.pcolormesh(*args, alpha=None, norm=None, cmap=None, vmin=None, vmax=None, shading='flat', antialiased=False, data=None, **kwargs)
    -> mesh : matplotlib.collections.QuadMesh

contour() 和 contourf() 分别绘制轮廓线和填充轮廓
    matplotlib.pyplot.contour(*args, data=None, **kwargs)
    -> c : QuadContourSet

    matplotlib.pyplot.contourf(*args, data=None, **kwargs)
    -> c : QuadContourSet

自动产生直方图并返回bin计数或预测 hist()
    matplotlib.pyplot.hist(x, bins=None, range=None, density=None, weights=None, cumulative=False, bottom=None, histtype='bar', align='mid', orientation='vertical', rwidth=None, log=False, color=None, label=None, stacked=False, normed=None, *, data=None, **kwargs)
    -> n : array or list of arrays
       The values of the histogram bins. See normed or density and weights for a description of the possible semantics. If input x is an array, then this is an array of length nbins. If input is a sequence of arrays [data1, data2,..], then this is a list of arrays with the values of the histograms for each of the arrays in the same order.

       bins : array
       The edges of the bins. Length nbins + 1 (nbins left edges and right edge of last bin). Always a single array even when multiple data sets are passed in.

       patches : list or list of lists
       Silent list of individual patches used to create the histogram or list of such list if multiple input datasets.
"""

#%%
# 展现如何组合Normalization和Colormap实例来画"levels" 以pxolor(), pcolormesh()和imshow()类型图, 
# 方式与contour/contourf的levels关键字参数相似
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.colors import BoundaryNorm
from matplotlib.ticker import MaxNLocator
import numpy as np


# make these smaller to increase the resolution
dx, dy = 0.05, 0.05

# generate 2 2d grids for the x & y bounds
y, x = np.mgrid[slice(1, 5 + dy, dy),
                slice(1, 5 + dx, dx)]

z = np.sin(x)**10 + np.cos(10 + y*x) * np.cos(x)

# x and y are bounds, so z should be the value *inside* those bounds.
# Therefore, remove the last value from the z array.
z = z[:-1, :-1]
levels = MaxNLocator(nbins=15).tick_values(z.min(), z.max())


# pick the desired colormap, sensible levels, and define a normalization
# instance which takes data values and translates those into levels.
cmap = plt.get_cmap('PiYG')
norm = BoundaryNorm(levels, ncolors=cmap.N, clip=True)

fig, (ax0, ax1) = plt.subplots(nrows=2)

im = ax0.pcolormesh(x, y, z, cmap=cmap, norm=norm)
fig.colorbar(im, ax=ax0)
ax0.set_title('pcolormesh with levels')


# contours are *point* based plots, so convert our bound into point
# centers
cf = ax1.contourf(x[:-1, :-1] + dx/2.,
                  y[:-1, :-1] + dy/2., z, levels=levels,
                  cmap=cmap)
fig.colorbar(cf, ax=ax1)
ax1.set_title('contourf with levels')

# adjust spacing between subplots so `ax1` title and `ax0` tick labels
# don't overlap
fig.tight_layout()

plt.show()


#%%
# 直方图
# 选择不同的bin计数和sizes能明显的影响直方图的形状
import numpy
import matplotlib
import matplotlib.pyplot as plt

numpy.random.seed(19680801)

mu = 100
sigma = 15
x = mu + sigma * numpy.random.randn(437)

num_bins = 100

fig, ax = plt.subplots()

n, bins, patches = ax.hist(x, num_bins, density=1)
print(n, "\n", bins, "\n", patches)

y = ((1/(numpy.sqrt(2*numpy.pi) * sigma))*numpy.exp(-0.5*(1/sigma*(bins-mu))**2))
ax.plot(bins, y, "--")
ax.set_xlabel("Smarts")
ax.set_ylabel("Probability desity")
ax.set_title(r"Histogram of IQ: $\mu=100$, $\sigma=15$")

fig.tight_layout()
plt.show()