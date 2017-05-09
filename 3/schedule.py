import Queue
import random
import time
import os
import subprocess

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
    child_pool = Queue.Queue()
    cpu_sum = 0
    mem_sum = 0
    c = 0.3

    def __init__(self, wq):
        print ("Create a process queue.")
        self.wq = wq

    def run(self):
        p = self.wq.get()
        child = subprocess.Popen(["./process", str(int(p.cpu*100)), str(int(p.mem*100))])
        print "run a process pid:", child.pid, "with cpu:"+str(p.cpu)+"% mem:"+str(p.mem)+"%"
        self.child_pool.put(child)
        self.pq.put(p)
        self.cpu_sum += p.cpu
        self.mem_sum += p.mem

    def drop(self):
        #pros = os.popen("ps -e | grep process")
        #plist = pros.read()
        #print plist
        #drop_p = plist.split('\n')[0]
        #print "Drop ", drop_p
        #drop_pid = drop_p.split(' ')[1]
        #print "Pid ", drop_pid
        p = self.pq.get()
        child = self.child_pool.get()
        print "Set pid:", child.pid, " to waiting queue!"
        child.kill()
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

    time.sleep(8)

    print " "
    print " "






