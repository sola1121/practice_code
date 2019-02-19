import pandas as pd
from sklearn import model_selection

file_dir = "./dat/iris2.csv"
data_frame = pd.read_csv(file_dir, index_col=False)

print(data_frame.tail(10), end='\n\n')

xlst, ysgn = ["x1", "x2", "x3", "x4"], "xid"
x, y = data_frame[xlst], data_frame[ysgn]

print(xlst, ysgn, sep="     ", end='\n\n')

print(x.tail(), "\n")   # pandas.core.series.Series
print(y.tail(), "\n")

# https://scikit-learn.org/stable/modules/generated/sklearn.model_selection.train_test_split.html#sklearn.model_selection.train_test_split
# train_test_split(训练数据集, 训练数据集对应的结果集, test_size=样本占比或个数, random_state=随机数种子)
x_train, x_test, y_train, y_test = model_selection.train_test_split(x, y, test_size=0.7, random_state=1)

print(x_train.tail(), "\n", x_test.tail(), "\n")

x_test.index.name, y_test.index.name = "xid", "xid"

# 用于训练的
# x_train: pandas.core.frame.DataFrame
# x_test: pandas.core.frame.DataFrame
# 用于测试的
# y_train: pandas.core.series.Series
# y_test: pandas.core.series.Series
