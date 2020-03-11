// Name: YoungA Lee
// Seneca Student ID: 048417083
// Seneca email: yalee2@seneca.ca
// Date of completion: Fab 17 2020
//
// I confirm that the content of this file is created by me,
//  with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include<iostream>
#include<string>

using namespace std;

namespace sdds {
	template<class T>
	class Collection {
		string _name{};
		T* _item;
		size_t _size;
		void (*functionptr)(const Collection<T>&, const T&);

	public:
		Collection(string name) {
			_name = name;
			_item = nullptr;
			_size = 0;
			functionptr = nullptr;
		}
		Collection(const T&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] _item;
		}
		const string& name() const {
			return _name;
		}
		size_t size() const {
			return _size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			functionptr = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool go = true;

			for (auto i = 0u; i < _size; i++) {
				if (_item[i].title() == item.title()) go = false; // if item is same with _item, will memory allocated 
			} 
			if (go) {
				T* temp = new T[_size + 1];		//copy _item to temp
				for (auto i = 0u; i < _size; i++) {
					temp[i] = _item[i];
				}						
				if (_item != nullptr) { // define _item nullptr 
					delete[] _item;
					_item = nullptr;
				}
				temp[_size] = item;		
				_size++;				
				_item = temp;			
				temp = nullptr;			
				if (functionptr != nullptr) {
					functionptr(*this, item);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= _size) throw out_of_range("Bad index [" + to_string(idx) + "]. Collection has [" + to_string(_size) + "] items.");
			else return _item[idx];
		}
		T * operator[](string title) const {
			bool go = false;
			size_t index;
			for (auto i = 0u; i < _size; i++) {
				if (_item[i].title() == title) {
					index = i;
					go = true;
				}
			}
			if (go) 
				return &_item[index];
			
			else 
				return nullptr;
		}
		friend ostream& operator<<(ostream& os, const Collection<T>& b1) {
			for (auto i = 0u; i < b1._size; i++) os << b1[i];
			return os;
		}
	};
}
#endif // !SDDS_COLLECTION_H

