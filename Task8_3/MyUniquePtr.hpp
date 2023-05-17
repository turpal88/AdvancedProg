#pragma once

template<typename T>
class MyUniquePtr {

public:
	MyUniquePtr() : obj(nullptr) {}
	MyUniquePtr(T* my_obj) : obj(my_obj) {
		std::cout << "Создался объект класса MyUniquePtr" << std::endl;
	}
	
	T& operator*() {
		std::cout << "Я объект класса MyUniquePtr и я вернул разыменованный объект" << std::endl;
		return *obj;
	}
	MyUniquePtr& operator=(const MyUniquePtr& right) = delete;
	MyUniquePtr(const MyUniquePtr& right) = delete;
	T* release() {
		T* temp = this->obj;
		this->obj = nullptr;
		std::cout << "Я объект класса MyUniquePtr и я вернул сырой указатель через свой метод release()" << std::endl;
		return temp;
	}
	~MyUniquePtr() {
		delete[] this->obj;
		std::cout << "Я объект класса MyUniquePtr и я самоуничтожился" << std::endl;
	}
private:
	T* obj;

};
