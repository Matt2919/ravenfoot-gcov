#include "Vector.h"
#include <stdexcept>
#include <algorithm>

// YOU: Implement everything in Vector.h
// REMEMBER TO ERROR CHECK AND VET EVERYTHING!

	Vector::Vector(){
		cap =10'000'000;
		size =0;
		data = new int[cap]{};
		} 

	
	int* Vector::begin() {
			return &data[0];
}
	int* Vector::end() {
			return &data[size];
			}
	void Vector::insert(int pos, int newData) {//idk what would happen to the og array in mem but fuck it we ball
	for (int i = size; i>pos; i--) {
		data[i]=data[i-1];

	}
	data[pos] = newData;
	size++;

}

	void Vector::erase(int pos) {//same thing as insert, leaves an array <UNTESTED LMAO>
		int* temp;
		temp = new int[cap];
		for(int i =0; i<size; i++) {
		if (i<pos) temp[i] = data[i];
		else if (i>=pos) {
			temp[i] = data[i-1];
		}
		size--;
		delete[] data;
		data = temp;

	}
}
	int& Vector::at(const int pos) {
		if (pos>size) throw std::runtime_error("OUT OF BOUNDS LMAO");
		else 
			return data[pos];
	}
	int Vector::operator[](int key) {
		return data[key];
	}
	int Vector::front() {
	if (size>0)
			return data[0];
	else return -1;
	}
	int Vector::back() {
			return data[size-1];
	}
	bool Vector::isEmpty() { //pretty fun way of doing it lol
		return size;
	}

	//super funky and i dont enjoy this one
	bool Vector::contains(int key) {
			auto it = std::find(begin(), end(), key);
			if (it!=end()) return true;
			else return false;
}

	void Vector::resize(int newCapacity) {
		size = newCapacity;
	}
	int Vector::get_size() { //you're not gonna believe what this does
		return size;
	}
	int Vector::get_capacity() { //says what it does on the tin lmao
		return cap;
	}
	void Vector::reserve(int reserveSapce) {
		cap = reserveSapce;	
	}
	void Vector::clear() { //it works lol
		size = 0;
	}
	void Vector::push_back(const int newVal) {
	data[size]= newVal;
	size++;
	}
	void Vector::pop_back() {
		size--;
			}

	void Vector::print_vec() {
	for (int i =0; i<size;i++){
		std::cout<<data[i] <<std::endl;
	}

}








	Vector::~Vector(){ delete[] data;} //thingy to release mem






