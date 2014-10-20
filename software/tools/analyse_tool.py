import serial
import time
import threading
import Queue
import sys
import ast
from optparse import OptionParser

buff = Queue.Queue(maxsize=0)  

class read_serial(threading.Thread):
    def __init__(self, ser="COM5",sleeptime=0.05):
        threading.Thread.__init__(self)
        self.sleeptime = sleeptime
        try:
            self.ser = serial.Serial(ser+":", baudrate=115200)
        except:
            print "ERROR:can't open serial port"
            sys.exit(0)

    def run(self):
        while 1:                                                                  
            time.sleep(self.sleeptime)
            if self.ser.inWaiting():
                length = self.ser.inWaiting()
                data = bytearray(length)
                self.ser.readinto(data)
                for i in range(length):
                    buff.put(data[i])
                
class analyse_data(threading.Thread):
    def __init__(self,sleeptime):
        threading.Thread.__init__(self)
        self.sleeptime = sleeptime
    
    def print_gesture(self,gesture):
        if gesture == 1:
            print "LEFT",
        elif gesture == 2:
            print "RIGHT",
        elif gesture == 3:
            print "UP",
        elif gesture == 4:
            print "DOWN",
        else :
            print "?",

    def run(self):
        while 1:
            time.sleep(self.sleeptime)
            while not (buff.empty()):
                data = buff.get()
                if (data == 0xF0):
                    # Raw input data
                    data = buff.get()
                    print "input:",data,"---{0:03b}".format(data)
                    buff.get()
                    continue
                elif (data == 0xF2):
                    # Scheme data
                    print "Scheme:",
                    for i in range(10):
                        print "%d" % buff.get(),
                    print "\n"
                    buff.get()
                    continue
                elif (data == 0xF4):
                    # second scheme
                    print "Component Scheme:",
                    for i in range(10):
                        print "%d" % buff.get(),
                    print "\n"
                    buff.get()
                    continue
                elif (data == 0xF6):
                    print "Gesture: ",
                    data = buff.get()
                    if (data&0xF0):
                        self.print_gesture(data>>4)
                        print "+",
                        self.print_gesture(data&0xF)
                        print "\n"
                    else :
                        self.print_gesture(data)
                        print "\n"
                    buff.get()
                    continue
                else:
                    buff.get()
                    if (buff.qsize() == 0):
                        buff.task_done()
                    continue
                
                    


if __name__ == "__main__":
    try:
        parser = OptionParser()
        parser.add_option("-p","--port",action="store",default="COM5",dest="port")
        opt,remainder = parser.parse_args()
        thread1 = read_serial(opt.port,0.05)
        thread2 = analyse_data(0.05)
        thread1.daemon = True
        thread2.daemon = True
        thread1.start()
        thread2.start()
        while 1:
            time.sleep(1)
    except  KeyboardInterrupt:
        sys.exit(0)    

            
        


