# MILESTONE ONE: Vectors

Github Classroom Link: https://classroom.github.com/a/2n5hO6pU

## Introduction
Welcome to your *first* Milestone project. For this project you will work in
your group to benchmark Vectors using the [Standard Template Library(STL)](https://cppreference.com),
[ChatGPT](chat.openai.com), and one you will make entirely on your own.

This may seem really daunting, but the importance of learning data structures 
is extremely important. Through these Milestone projects, you will be benchmarking 
multiple data structures then comparing and contrasting how each data structure 
does with ***insert***, ***search***, and ***delete***; the main operations 
of each data structure.

Vectors are the vanilla ice cream of data structures and are really good 
at inserting and deleting from the back, but not from the front. Why are they
slow in the front then? Well that's a great question and you'll answer it 
during the project. Some people will start out with a vector to store their 
data until they find a reason to go to another data structure that is better
depending on what they are using their data for such as finding your Driver's
License in the DMV database. Vectors might not be the best choice here. With
these projects, you'll be working on multiple data structures and verify for 
yourself which data structure is quickest depending on the main operations 
that I went over at the beginning. This begins what is expected of you for
this project. Read on for your task.

## Project Assignment

As mentioned, you will be benchmarking the [vector](https://en.cppreference.com/w/cpp/container/vector) 
container class in three separate implementations:

+ Standard Template Library (`#include <vector>`)
+ ChatGPT (`VectorGPT.h` and `VectorGPT.cc`)
+ Your Implementation (`Vector.h` and `Vector.cc`)

The easiest of this is to implement the functions already existing in the Standard Library 
and benchmark Insert, Searching, and Deleting with `#include <vector>`. You will not do
anything other than declare a vector as you normally would in `main.cc` then call the functions
that match the operation given. The difficulty is increased when working on ChatGPT and 
your implementation of Vector. During this project, you will learn separate compilation 
and how Makefiles work. Typically, a .h file holds the **DECLARATIONS** of a function so like this:

This is an example of a file named `Foo.h`:
```cpp
#pragma once // Header Guard

#include <string>

class Foo {
    private:
        int age = 0;
        std::string address;
    public:
        int get_age() const;
        std::string get_address() const;
};
```

Notice how the class contains all the member variables and just my DECLARATIONS in this file. 
In .h files you are basically setting up the class or putting your function declarations in a 
its own file that way you can go and **DEFINE** those functions in your .cc file. Notice
how you have two files named the same thing but just one as .h and the other as .cc.

This leads to what the .cc is for. You will DEFINE the functions that are in your .h file.
Here is an example of a file named `Foo.cc`:

```cpp
    #include "Foo.h" // Notice how I included the file name up here?

    int Foo::get_age() const { return age; }
    std::string Foo::get_address() const { return address; }
```

Notice how the cpp file doesn't contain everything from the .h? That's because we *include*d it in
our .cc file. Notice also for me to not get compiler errors, I needed to use the **Scope Resolution Operator**
to inform the compiler I wanted Foo's get_age() function. The only other thing you need to know regarding
separate compilation for now is that you **must** `#include` your .h Vector files in `main.cc`.

Now for the project, you will need to use *Proper Class Design* to implement the yours and ChatGPT's Vector class. 
This means you will have constructors and destructors in your public section of your class. 
You will also implement the following functions in your VectorGPT.h and Vector.h files:

+ void begin()
+ void end()
+ int at(int pos)
+ operator[] 
+ int front()
+ int back()
+ bool contains(int key)
+ bool isEmpty()
+ int get_size()
+ int get_capacity()
+ void clear()
+ void insert(int pos, int newData)
+ void erase(int pos)
+ void push_back(int newData)
+ void pop_back()
+ void resize(int newSize)
+ void print_vec()

You will need to vet for proper inputs at all times and throw exceptions if something does
not make sense such as a negative value for a position.

Once you are done with the Vector classes and implementing them you will need to go implement
tests to ensure correctness. See how your Vector does versus the STL and if it's getting the same
output,move onto benchmarking.

## Benchmarking

Benchmarking is the whole point of the project. Testing the main operations with a vector,
recording the times, and gathering information based on that. During the benchmarking stage,
you will create the following files at these sizes:

+ insertOnly
    + 10
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000
+ insertAndSearch
    + 10
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000
+ MixTape 
    + 10
    + 100
    + 1000
    + 10000
    + 100000
    + 250000
    + 500000
    + 750000
    + 1000000

For insertOnly, you will test how your code handles push_back() and insert.
The only commands in insertOnly should be *PUSH* and *INSERT*. For insertAndSearch,
it will be the same as insertOnly except, you now have to include *SEARCH*. You should
test SEARCH extensively to make it about half your commands per file. For MixTape, it 
will contain PUSH, INSERT, SEARCH, and *POP*. POP is the delete and you should call pop_back().

You will benchmark all those files on the STL Vector, Your Vector, and ChatGPT's Vector.
Now that is a lot of time. You're doing over 100 runs total on your data and it'd be a 
pain to sit down all day doing it by hand. Well that is why in your directory, you have 
access to scripts and a program to help you generate your data. We will go over this in 
class, but learning how to automate your life is an important skill. Don't be like the guy
at UCSD's computer lab!

## Report

At the very end of this, you need to write up a report (3-5 pages) detailing what you
learned from benchmarking the vectors and explain what you found. You must include
graphs showing how all three implementations did across your data. You should also include
your approach and you **must** answer this question: What was ChatGPT's error rate to your
code?

Once you are finished with the report, you need to review and give feedback on your group by 
RATting them out. Once you're done, I will push out a RAT program and you will give your 
feedback on each individual in your group, including yourself. ***THIS WILL NOT EFFECT YOURS OR 
YOUR GROUP MEMBER'S GRADES!*** Your feedback will help me select teams for the next round.

## Grading

To get a good grade on this project, you will need to be proactive and communicate with your 
group. Once you have completed the assignment, you must have pushed all your files to the GitHub 
classroom by the due date. Failure to do so will impact your grade. Even if you aren't happy with
how your project went, I ***highly*** recommend uploading whatever you have. The grade breakdown
will be as follows:

#### Grading Breakdown: 
1. All Vector Implementations: 12 points
    1. 2 points based off your implementation of the STL vector class.
    2. 4 points based off your implementation of the GPT vector class.
    3. 6 points based off your implementation of your vector class.
2. Benchmark Report: 10 points
   1. 4 points for writing the report (3-5 pages, other requirements, etc.).
   2. 2 points for graphs in report with proper formatting.
   3. 2 points for quality of report.
   4. 2 points for explaining what you did to debug.
3. RATting out for 3 points.

Total: 25 points

When grading your vector implementations, I will be looking for how well you implemented the 
functions from earlier in this README. The less you do, you will get fewer points. The more 
bugs your code contains, the fewer points you will get. Your report will be graded simply
if you did it, the quality of the report, graphing your data, and explaining what you did
to debug your code. Your last 3 points will be to ***Review All Teammates (RAT)***. These
points are gimme points for just participating in RATting out. **NO ONE'S GRADE WILL BE 
NEGATIVELY IMPACTED SO BE HONEST**. The only way you'd lose points is if you just don't 
RAT, so please RAT!

## Conclusion

At the end of this assignment, you will have a much better understanding of working in groups,
class design, debugging your code, and how vectors work. You will also be able to give the time 
complexity of them based on your report. This assignment is a small example of what upper-division
is like so take it seriously!

If you have any questions, ask me, Discord channel, or go to the [Tutorial Center](https://www.cloviscollege.edu/student-services/tutorial-center/index.html) for help. 
Good luck, have fun!
