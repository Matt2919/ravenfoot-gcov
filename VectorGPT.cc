// YOU: Have ChatGPT define the functions written in VectorGPT.h
// Remember to still error check and debug ChatGPT's code.

#include "VectorGPT.h"
using namespace std;

int* VectorGPT::begin() const {
	return data;
}

int* VectorGPT::end() const {
	return data + size;
}
	
int VectorGPT::get_size() const {
	return static_cast<int>(size);
}
	
int VectorGPT::get_capacity() const {
	return static_cast<int>(capacity);
}

bool VectorGPT::isEmpty() const {
	return size == 0;
}

void VectorGPT::resize(size_t new_capacity) {
	if (new_capacity < size) {
		throw std::invalid_argument("New capacity must be greater than old capacity");
	}
	int* new_data = new int[new_capacity];
	for (size_t i = 0; i < size; i++) {
		new_data[i] = data[i];
	}
	delete[] data;

	data = new_data;
	capacity = new_capacity;
}

void VectorGPT::clear() {
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

int& VectorGPT::at(size_t index) {
	if (index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

int& VectorGPT::operator[](size_t index) {
	return data[index];
}

int VectorGPT::front() {
	if (size == 0) {
		throw std::out_of_range("Vector is empty");
	}
	return data[0];
}

int VectorGPT::back() {
	if (size == 0) {
		throw std::out_of_range("Vector is empty");
	}
	return data[size - 1];
}

void VectorGPT::push_back(const int& value) {
	if (size >= capacity) {
		capacity = (capacity == 0) ? 1 : capacity * 2;
			
		int* new_data = new int[capacity];
		
		for (size_t i = 0; i < size; i++) {
				new_data[i] = data[i];
		}
			
		delete[] data;
		data = new_data;
	}	
	data[size++] = value;
}

void VectorGPT::pop_back() {
	if (size > 0) {
		size--;
	}
}

void VectorGPT::insert(size_t pos, int newData) {
	if (pos > size) {
		throw std::out_of_range("Insert position out of range");
	}
	if (size >= capacity) {
		capacity = (capacity == 0) ? 1 : capacity * 2;
		
		int* new_data = new int[capacity];
		
		for (size_t i = 0; i < pos; i++) {
			new_data[i] = data[i];
		}
		new_data[pos] = newData;

		for (size_t i = pos; i < size; i++) {
			new_data[i + 1] = data[i];
		}
		delete[] data;
		data = new_data;
		
		size++;
	}
	else {
		for (size_t i = size; i > pos; i--) {
			data[i] = data[i - 1];
		}
		data[pos] = newData;
	
		size++;
	}
}

void VectorGPT::erase(size_t pos) {
	if (pos >= size) {
		throw std::out_of_range("Erase position out of range");
	}
	for (size_t i = pos; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

bool VectorGPT::contains(const int& key) {
	for (size_t i = 0; i < size; i++) {
		if (data[i] == key) {
			return true;
		}
	}
	return false;
}


