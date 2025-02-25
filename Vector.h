// These are called header guards. These prevent you from
// copying the whole file more than one time.
// #pragma once does the same thing
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

// Remember to use proper class design when
// making your Vector class (ie Constructors,
// Destructors, etc.). YOU MUST FOLLOW RULE OF THREE!
class Vector {
    private:
        int* data; // We will deal with templates later, for now benchmark with ints
		int size;
		int cap;
    public:
        // YOU: Declare the following functions:
        // NOTE: Do not DEFINE these functions in this file
        // You will DEFINE in the .cc file of the same name.
        // Vector Functions:
		Vector();
		   int* begin();
		   int* end();
		   void insert(int pos, int newData);
		   void erase(int pos);
           int& at(const int pos);
           int operator[](int key);
           int front(); //- 1 liner
           int back(); //- 1 liner
           bool isEmpty(); //- 1 liner
           bool contains(int key);
           void resize(int newCapacity); //- 1 liner
           int get_size(); //- 1 liner
           int get_capacity(); //- 1 liner
		   void reserve(int reserveSpace);
           void clear(); //- 1 liner
           void push_back(const int newVal);
           void pop_back();
		   void print_vec();
	~Vector();
           
};

#endif
