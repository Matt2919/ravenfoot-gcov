#include "VectorSTD.h"
using namespace std;
		
		VectorSTD::VectorSTD()
		{
			vector<int> vec;
		}

		auto VectorSTD::begin() {
			return vec.begin();
		}
		auto VectorSTD::end() { 
			return vec.end(); 
		}
		void VectorSTD::insert(int pos, int newData) {
			vec.insert(vec.begin() + pos, newData);
		}
		void VectorSTD::erase(int pos) {
			vec.erase(vec.begin() + pos);
		}
		int VectorSTD::at(int pos) {
			return vec.at(pos);
		}
		int VectorSTD::operator[](int pos){
			return vec[pos];
		}
		int VectorSTD::front() {
			return vec.front();
		}
		int VectorSTD::back() {
			return vec.back();
		}
		bool VectorSTD::empty() {
			return vec.empty();
		}
		bool VectorSTD::contains(int key){
			auto it = find(vec.begin(), vec.end(), key);
			if (it != vec.end())	{
				return true;
			}
			return false;
		}
		void VectorSTD::resize(int newCapacity){
			vec.resize(newCapacity);
		}
		int VectorSTD::get_size() {
			return vec.size();
		}
		int VectorSTD::get_capacity() {
			return vec.capacity();
		}
		void VectorSTD::reserve(int reserveSpace) {
			vec.reserve(reserveSpace);
		}
		void VectorSTD::clear() {
			vec.clear();
		}
		void VectorSTD::push_back(int newVal) {
		//	cout <<newVal<< " ";
			vec.push_back(newVal);
			
		}
		void VectorSTD::pop_back() {
			vec.pop_back();
		}

		void VectorSTD::print_vec() {
			for (int i = 0; i < vec.size(); i++) {
				cout << vec.at(i) << endl;
			}
		}

