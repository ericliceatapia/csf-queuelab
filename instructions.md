# Project: Queue Lab
## Computer Systems Fundamentals
## Assessing Your C Programming Skills
## Due: September 9 23:59


## Logistics
- This assignment is due September 9 by 23:59.
- This is an individual assignment.
- Make sure your source code is updated on your GitHub Classroom repository by the due date / time.
- This project is worth 100 points.


## Introduction
Plan to start early enough to get it done by the due date. A well-prepared student can complete it in 1 - 2 hours, but it may require longer if you have not done much C programming.

This is an individual project. All handins are electronic via GitHub Classroom.  Your project will be tested on `babbage.cs.tcu.edu`.   


## Overview
This lab will give you practice in the style of programming you will need to be able to do proficiently, especially for the later assignments in the course. The material covered _should_ all be review for you. Some of the skills tested are:

- Explicit memory management, as required in C.
- Creating and manipulating pointer-based data structures.
- Implementing robust code that operates correctly with invalid arguments, including `NULL` pointers.

The lab involves implementing a queue, supporting both last-in, first-out (LIFO) and first-in, first-out (FIFO) queueing disciplines. The provided underlying data structure is a singly-linked list, enhanced to make some of the operations more efficient.


## Downloading the Assignment
No doubt if you are reading this project description, then you have already created your project repository in GitHub Classroom.  Download your repository to your account on `babbage` using the `git clone` command.  


## Building and Updating Your Project
There are several files in the project subdirectory.  The only two files you will be editing will be `queue.h` and `queue.c`.  

To build/compile your project use the supplied Makefile and simply type `make`.  This will compile your project and create an executable named `qtest`.  

As you complete the various parts of this assignment, you will want to update your GitHub Classroom repository using various `git` commands from the command line.

- `git status` - will show you the status of files changed and included in this project
- `git add .` - will move any changes you made to the staging area
- `git commit -m "Documentation message goes here"` - will commit your changes and update the documentation string.
- `git push` - will push your code from the staging area to your repository on GitHub Classroom.


## Underlying Data Structure
The file `queue.h` contains the declarations of the following structures:
```c
/* Linked list element...this is a queue node */
typedef struct node_t {
   int value;
   struct node_t *next;
} Node_t;

/* header/descriptor record for a queue */
typedef struct {
   Node_t *head; /* Linked list of elements */
} Queue_t;
```

The top-level representation of a queue is a structure of type `Queue_t`.  In the starter code, this structure contains only a single field `head`, but you will want to add other fields. The queue contents are represented as a singly-linked list, with each element represented by a structure of type `Node_t`, having fields `value` and `next` storing a queue value and a pointer to the next list element, respectively.  While all functions in the assignment can be implemented without changes to  `Node_t`, you are welcome to make changes to `Node_t`, such as converting a singly-linked list to a doubly-linked list.

In our C code, a queue is a pointer of type `Queue_t *`.  We distinguish two special cases: a `NULL` queue is one for which the pointer is set to `NULL`.  An empty queue is one pointing to a valid `Queue_t` structure with a head field set to `NULL`. Your code will need to deal properly with both of these cases, as well as queues containing one or more elements.

## Programming Task
Your task is to modify the code in `queue.h` and `queue.c` to fully implement the following functions.

- `q_new()`: Create a new, empty queue.
- `q_free()`: Free all storage used by a queue.
- `q_insert_head()`: Attempt to insert a new element at the head of a queue (LIFO discipline).
- `q_insert_tail()`: Attempt to insert a new element at the tail of the queue (FIFO dicipline).
- `q_remove_head()`: Attempt to remove the element at the head of the queue.
- `q_size()`: Compute the number of elements in the queue.
- `q_reverse()`: Reorder the list so that the queue elements are reversed in order.

More details can be found in the comments in these two files, including how to handle invalid operations (e.g., removing from an empty or `NULL` queue), and what side effects and return values the functions should have.

The following are some important notes about how you must implement these functions.

- You are required to implement `q_new()` and  `q_insert_head()` with `malloc()` or `calloc()` when dynamically allocating memory.
- Two of the functions: `q_insert_tail()` and `q_size()` will require some effort on your part to meet the required performance standards. The naive implementations would require $O(n)$ steps for a queue with $n$ elements.  It is required that your implementations operate in time $O(1)$, i.e., that the time required is independent of the queue size. You can do this by including other fields in the `Queue_t()` data structure and managing these values properly as list elements are inserted, removed and reversed.
- You must implement `q_reverse()` in a way that does not require allocating any additional memory.  Instead, your code should modify the pointers in the existing list. Implementations that directly or indirectly call `malloc()`, `calloc()`, or `free()` as part of the reverse operation will cause an error.
- Your program will be tested on queues with over 1,000,000 elements.  You will find that you cannot traverse such long lists using recursive functions, since that would require too much stack space.

## Running and Testing Your Project
The simplest way to run and test your project is to use the following commands.
```sh
linux$ make
linux$ make test
<lots of output generated by the autograder>
linux$
```
You can also run the Python script to do the testing yourself.
```sh
linux$ ./driver.py
<lots of output>
linux$
```
The "manual" way to test your program is to run the `qtest` program itself.  `qtest` provides a command interpreter that can create and manipulate queues.

Run `./qtest -h` to see the list of command-line options.  When you execute `./qtest`, it will give a command prompt `cmd>`.  Type `help` to see a list of available commands.

The following file (`traces/traces-eq.cmd`) illustrates an 
```text
# Demonstration of queue testing framework
# Initial queue is NULL.
show
# Create empty queue
new
# Fill it with some values. First at the head
ih 2
ih 1
ih 3
# Now at the tail
it 5
it 1
# Reverse it
reverse
# See how long it is
size
# Delete queue. Goes back to a NULL queue.
free
# Exit program
quit
```
You can see the effect of these commands by operating `qtest` in batch mode:
```sh
linux> ./qtest -f traces/trace-eq.cmd
```
With the starter code, you will see that many of these operations are not implemented properly.

The `traces` directory contains 15 trace files, with names of the form `trace-k-cat.txt`, where $k$ is the trace number, and $cat$ specifies the category of properties being tested.  Each trace consists of a sequence of commands, similar to those shown above. They test different aspects of the correctness, robustness, and performance of your program. You can use these, your own trace files, and direct interactions with `qtest` to test and debug your program.


## Evaluation
Your program will be evaluated using 15 traces. You will given credit (either 6 or 7 or 8 points, depending on the trace) for each one that executes correctly, summing to a maximum score of 100.

The driver program `driver.py` runs `qtest` on the traces and computes the score. You can invoke it directly with the command:
```sh
linux$ ./driver.py
```
or with the command:
```sh
linux$ make test
```
