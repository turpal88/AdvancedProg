#pragma once

/*
#ifdef MYVECTOR_EXPORTS
#define MYVECTOR_API __declspec(dllexport)
#else
#define MYVECTOR_API __declspec(dllimport)
#endif
*/
#include <initializer_list>

template<typename T>
class MyVector {

public:
	MyVector() : count(0), _capacity(1) {
		arr = new T[_capacity];
	}
	MyVector& operator=(const MyVector& right) { // перегрузка оператора присваивания
		if (this != &right) {
			this->count = right.count;
			this->_capacity = right._capacity;
			T* new_arr = new T[right._capacity];
			delete[] this->arr;
			for (int i = 0; i < _capacity; i++) new_arr[i] = right.arr[i];
			this->arr = new_arr;
		}

		return *this;

	}
	MyVector(const MyVector& right) { // конструктор копирования
		this->count = right.count;
		this->_capacity = right._capacity;
		this->arr = new T[right._capacity];
		for (int i = 0; i < _capacity; i++) arr[i] = right.arr[i];

	}
	MyVector(std::initializer_list<T> l) : MyVector(l.size()) { //использовал объект std::initializer_list
		unsigned int j = 0;
		for (int i = *l.begin(); j < l.size(); j++) {
			arr[j] = *l.begin() + j;
			//j++;
		}
	}
	MyVector(int count) {
		if (count <= 0) throw std::out_of_range("Количество параметров вектора меньше или равно нулю!");
		else {
			this->count = count;
			arr = new T[count];
			_capacity = count;
		}

	}
	T at(unsigned int index) {
		if (index < 0 || index > count - 1) throw std::out_of_range("Индекс элемента вектора за пределами его размеров!");
		else return arr[index];
	}
	void push_back(T value) {

		if (_capacity == count) {
			unsigned int new_capacity = _capacity * 3;
			T* new_arr = new T[new_capacity];
			for (unsigned int i = 0; i < count; i++) new_arr[i] = arr[i];
			delete[] arr;
			arr = new_arr;
			_capacity = new_capacity;
		}
		arr[count++] = value;

	}
	unsigned int size() {
		return count;
	}
	unsigned int capacity() {
		return _capacity;
	}
	~MyVector() {
		delete[] arr;
	}

private:
	unsigned int count;
	T* arr;
	unsigned int _capacity;
};
