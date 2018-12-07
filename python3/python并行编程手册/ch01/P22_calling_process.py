import os
import sys

program = "python3"
print("Process calling")
arguments = ["P22_called_process.py"]

os.execvp(program, (program, ) + tuple(arguments))   # 执行描述, 覆盖现有进程
print("Good Bye.")  # 因为所在进程被覆盖(后台), 所以不会打印
