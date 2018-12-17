import multiprocessing

def foo(i):
    print("called function in process: %s" %i)

if __name__ == "__main__":

    process_jobs = list()

    for i in range(5):
        ps = multiprocessing.Process(target=foo, args=(i,))

        process_jobs.append(ps)
        ps.start()
        ps.join()
