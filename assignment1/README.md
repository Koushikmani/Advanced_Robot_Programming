## ARP_ASSIGNMENT-1##
## NAME: KOUSHIKMANI MASKALMATTI LAKSHMAN ##
## MATRICOLA: S5053566 ##

**AIM**

Design and code a strange arithmetic integer this calculator able to exdcute the 4 basic operations, as well as a compbined arithmetic expression.
The structure of the calculator may seem bombastic, nevertheless is a simplified skeleton of real complex calculators.

## About the Assignment

The assignment has 2 main requirements, that is to create a bombastic calculator that does basic operations in which the data is passed using named pipes and unnamed pipes. They are kept in 2 different folders. 
The program runs 4 basic operations:
1. Addition (represented by p)
2. Subtraction (represented by m)
3. Multiplication (represented by t)
4. Division (represented by d)

The program also gives an option of exiting the program by pressing x or X.

Inputs are taken from the user in the form of which operation they want to carry out and which 2 numbers do they want to use initially after which to continue with the usage of the calculator the user needs to specify the operation and the number. The result of the previous operation will be taken as the 1st input of the next operation.

Each folder consists of 6 files:
1. f.c which is the frontend process that takes inputs from the user and also reads values from the child processes that were created.

2. p.c is a child process which performs addition and returns value to the frontend process using either a named pipe or an unnamed pipe.

3. m.c is a child process which performs subtraction and returns value to the frontend process using either a named pipe or an unnamed pipe.

4. t.c is a child process which performs multiplication and returns value to the frontend process using either a named pipe or an unnamed pipe.

5. d.c is a child process which performs division and returns value to the frontend process using either a named pipe or an unnamed pipe.

6. makefile compiles all the c programs at once.

## Expected Result

1. Named Pipes
/Desktop/ARP_assignments/assignment1/named_pipes$ make
cc     f.c   -o f
f.c: In function ‘main’:
f.c:26:2: warning: implicit declaration of function ‘mkfifo’ [-Wimplicit-function-declaration]
   26 |  mkfifo(myfifo, 0666);
      |  ^~~~~~
cc     p.c   -o p
cc     m.c   -o m
cc     t.c   -o t
cc     d.c   -o d
/Desktop/ARP_assignments/assignment1/named_pipes$ ./f
 Select operator (p for sum, m for subtraction, t for product and d for division) 
 then press space and input the first number and then the second number 
 for all consequent operations enter operation and then the number
 p 5 5
Waiting for signal 
signal is received
5 p 5 = 10 
m 6
Waiting for signal 
signal is received
10 m 6 = 4 
t 10
Waiting for signal 
signal is received
4 t 10 = 40 
d 10
Waiting for signal 
signal is received
40 d 10 = 4 



2. Unnamed Pipes/Desktop/ARP_assignments/assignment1/unnamed_pipes$ make
cc     f.c   -o f
cc     p.c   -o p
cc     m.c   -o m
cc     t.c   -o t
cc     d.c   -o d
taz_devil@Master-Splinter:~/Desktop/ARP_assignments/assignment1/unnamed_pipes$ ./f
 Select operator (p for sum, m for subtraction, t for product and d for division) 
 then press space and input the first number and then the second number 
 for all consequent operations enter operation and then the number
 p 10 25
Waiting for signal 
signal is received
10 p 25 = 35 
m 20
Waiting for signal 
signal is received
35 m 20 = 15 
t 20
Waiting for signal 
signal is received
15 t 20 = 300 
d 100
Waiting for signal 
signal is received
300 d 100 = 3 

