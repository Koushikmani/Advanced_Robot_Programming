import threading
import random
import time

#Class inherits threads
class Philosopher(threading.Thread):
	#To check if everyone is done eating.
    running = True  

    def __init__(self, index):
        threading.Thread.__init__(self)
        self.index = index

    # Initialize and start the process of the Philosophers thinking, eating and leaving.

    def run(self):
        while(self.running):
            print ('Philosopher %s is thinking. '% self.index)
            time.sleep(random.randint(0,5))
            self.dine()      
 
    def dine(self):			
        print ('Philosopher %s starts eating. '% self.index)
        time.sleep(random.randint(1,15))
        self.running = False
        print ('Philosopher %s has completed eating.' % self.index)

def main():
   
    philosophers= [Philosopher(i) for i in range(5)]

    Philosopher.running = True
    for p in philosophers: p.start()
    time.sleep(30)
    Philosopher.running = False
    print ("The round table process has been completed. All the philosophers have left the restaurant")
 

if __name__ == "__main__":
    main()
    
