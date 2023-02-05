DINING PHILOSOPHER PROBLEM

This program is tackles the problem of the Dining Philosopher's Problem using Sockets as the IPC form of communication in python script.

## What is the problem?

There are 5 philosophers in this problem. For the sake of making it easy to understand, I have named them as Philosophers 1 to 5. The problem is inspired by the idea of eating spaghetti around a table with forks being placed between each pair of adjacent philosophers.
The process is quite simple and as follows:
1. Each philosopher alternatively thinks and eats. But they can only eat when both left and right forks are with them.
2. Each fork can only be held by a philosopher and hence a philospoher can use it only if it is not being used by another philosopher (Similar to the traditional chopstick problem). When a philosopher is done eating, they need to place the forks on the table in other for it to be used by others.
3. Philosophers can eat endlessly.

## How the Program works?

1. 5 child processes are created for the philosophers and 5 child processes are created for the forks. Hence a total of 10 processes are created. The child processes takes care of the forks being given or taken away. 
2. There are 3 states of the philosophers: 
	i. Thinking
	ii. Waiting, and
	iii. Eating
The time estimated here for the eating time is 75 seconds in total.

3. Sockets are used for the interprocess communication. There are 2 sides of the process: The server side and the client side.

4. A philosopher gives the fork if their request for another one is rejected by the server, hence eliminating a deadlock situation.

5. Finally, the entire status sequence is printed out in the terminal. I have used a datagram type of socket to initiate each connection between an output process and the philosopher process.


## Running the Program
In order to run the program there is a require of python3. The command to run the program is as follows:
	$ python dining_philosopher.py
