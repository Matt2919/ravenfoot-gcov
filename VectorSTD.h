#ifndef VECTORSTD_H
#define VECTORSTD_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class VectorSTD {
	private:
		std::vector<int> vec;

	public:
		VectorSTD();
		auto begin();
		auto end();
		void insert(int pos, int newData);
		void erase(int pos);
		int at(int pos);
		int operator[](int pos);
		int front();
		int back();
		bool empty();
		bool contains(int key);
		void resize(int newCapacity);
		int get_size();
		int get_capacity();
		void reserve(int reserveSpace);
		void clear();
		void push_back(int newVal);
		void pop_back();

		void print_vec();

};

#endif
