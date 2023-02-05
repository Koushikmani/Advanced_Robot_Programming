Dining Philosopher Problem

                                                                                              #ARP ASSIGNMENT-2#
                                                                                        KOUSHIKMANI MASKALMATTI LAKSHMAN
                                                                                             (MATRICOLA:S5053566)

**AIM**

To realize a server for the 5 dining philosophers
the server receives commands from two processes, each one in a separate shell, P1 and P2
you can ask P1|P2 to:

a. makes a philosopher to enter, sit and eat endlessly
b. makes a philsopher to stop eating and exiting

Philosophers must be enqued on a fifo basis upon entering.
The server has its own shell in which it writes its status (philosophers sitting and eating, philosophers waiting).


##About the Assignment

This assignment is the classic example of the dining Philosopher problem where there are 5 philosophers sitting around a table.
The philosophers have 3 stages: 
1. To think
2. To eat
3. To leave the restaurant.

The philosophers can sit and eat endlessly for the specified time after which they leave the restaurant.

## Code Description

The code has been executed in python script and uses threads to create processes and communicate with the pipes. 
def __init__(self, index) initializes the thread.
def dine(self) means the philosopher comes and eats at random times between a given set of time after which they leave the restaurant.

## Requirement

The code requires python3 and the syntax to execute the running is:
		python3 dining_philosopher.py

## Expected Result

Philosopher 0 is thinking. 
Philosopher 1 is thinking. 
Philosopher 2 is thinking. 
Philosopher 3 is thinking. 
Philosopher 4 is thinking.
 
Philosopher 4 starts eating. 
Philosopher 1 starts eating. 
Philosopher 0 starts eating. 
Philosopher 2 starts eating. 
Philosopher 3 starts eating. 

Philosopher 2 has completed eating.
Philosopher 4 has completed eating.
Philosopher 1 has completed eating.
Philosopher 3 has completed eating.
Philosopher 0 has completed eating.

The round table process has been completed. All the philosophers have left the restaurant
