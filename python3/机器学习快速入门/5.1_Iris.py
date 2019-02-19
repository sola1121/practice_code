# http://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.html#pandas.DataFrame
# 快速的分类安德森鸢尾花卉数据集, 其中更具采集到的数据, 对花的种类进行分类

import pandas as pd

file_dir = "./dat/iris.csv"
data_frame = pd.read_csv(file_dir, index_col=False)   # pandas.core.frame.DataFrame
# print(data_frame)
print(data_frame.describe())

series = data_frame["xname"].value_counts()   # pandas.core.series.Series
print("\n\nxname\n", series)

# xname字段是字符, 将其数字化. 按1,2,3分别设置xid字段, 完成读取iris数据名称的矢量化操作
data_frame.loc[data_frame["xname"]=="virginica", "xid"] = 1
data_frame.loc[data_frame["xname"]=="setosa", "xid"] = 2
data_frame.loc[data_frame["xname"]=="versicolor", "xid"] = 3
data_frame["xid"] = data_frame["xid"].astype(int)
data_frame.to_csv("./tmp/iris2.csv", index=False)

print("\n\n", data_frame.describe())
print("\n\n新建了xid字段\n", data_frame["xid"].value_counts())
