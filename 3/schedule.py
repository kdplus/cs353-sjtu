import Queue
import random
import time


class Process:
    pid = 0
    cpu = 0
    mem = 0

    def __init__(self, pid, cpu, mem):
        self.pid = pid
        self.cpu = cpu
        self.mem = mem


class Sched:
    pq = Queue.Queue()
    wq = Queue.Queue()
    cpu_sum = 0
    mem_sum = 0
    c = 0.3

    def __init__(self, wq):
        print ("Create a process queue.")
        self.wq = wq

    def run(self):
        p = self.wq.get()
        self.pq.put(p)
        self.cpu_sum += p.cpu
        self.mem_sum += p.mem

    def drop(self):
        p = self.pq.get()
        self.wq.put(p)
        self.cpu_sum -= p.cpu
        self.mem_sum -= p.mem


wq = Queue.Queue()
# create some processes
for i in range(0,10):
    a = Process(i, random.random()/10, random.random()/10)
    wq.put(a)

s = Sched(wq);

while True:
    print ("Status of Schedule:")
    print ("Cpu:", s.cpu_sum, " Mem: ", s.mem_sum)
    print ("running process queue ----------------------")

    for i in range(0, s.pq.qsize()):
        p = s.pq.get()
        print (p.pid),
        s.pq.put(p)
    print (" ")

    print ("waiting process queue ----------------------")
    for i in range(0, s.wq.qsize()):
        p = s.wq.get()
        print (p.pid),
        s.wq.put(p)
    print (" ")


    if s.cpu_sum < s.c and s.mem_sum < s.c:
        s.run()
    else:
        s.drop()

    time.sleep(2)

    print " "
    print " "






