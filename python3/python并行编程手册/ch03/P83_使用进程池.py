import multiprocessing

def function_square(data):
    result = data * data
    return result


if __name__ == "__main__":

    inputs = list(range(100))
    po = multiprocessing.Pool(processes=4)
    # po_outputs = po.map(function_square, inputs)
    po_outputs = po.map_async(function_square, inputs)   # multiprocessing.pool.MapResult
    po.close()
    po.join()
    # print("Pool : ", po_outputs)
    print("Pool : ", po_outputs.get())   # multiprocessing.pool.MapResult 获取其结果
