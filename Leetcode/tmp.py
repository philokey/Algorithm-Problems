from threading import Thread
from queue import Queue
from time import sleep
q = Queue()
NUM = 2
JOBS = 10

def doSomething(args):
    print (args)

def working():
    while True:
        args = q.get()
        doSomething(args)
        sleep(1)
        q.task_done()

for i in range(NUM):
    t = Thread(target=working)
    t.setDaemon(True)
    t.start()

for i in range(JOBS):
    q.put(i)

q.join()