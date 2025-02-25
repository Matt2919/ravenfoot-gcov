// YOU: Have ChatGPT write a vector class named VectorGPT
// using proper class design and RULE OF THREE.
// NOTE: Do not DEFINE these functions in this file
// You will DEFINE in the .cc file of the same name.
/* Vector Functions:
   void begin()
   void end()
   void insert(int pos, int newData)
   void erase(int pos)
   int& at(int pos)
   int operator[]
   void front()
   void back()
   bool contains(int key()
   bool isEmpty()
   void resize(int newCapacity)
   int get_size()
   int get_capacity()
   void clear()
   void push_back(int newVal)
   void pop_back()
 */
#include <iostream>
using namespace std;

class VectorGPT {
private:
	int* data;
	size_t size;
	size_t capacity;

public:
	VectorGPT() : data (nullptr), size(0), capacity(0) {}
	~VectorGPT() {
		delete[] data;
	}

	int* begin() const;
	int* end() const;
	int get_capacity() const;
	int get_size() const;
	bool isEmpty() const;
	void resize(size_t new_capacity);
	void clear();
	int& at(size_t pos);
	int& operator[](size_t pos);
	int front();
	int back();
	void push_back(const int& value);
	void pop_back();
	void insert(size_t pos, int newData);
	void erase(size_t pos);
	bool contains(const int& key);
};


