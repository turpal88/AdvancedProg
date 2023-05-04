#include "MyVector.cpp"
#include <iostream>
#include "windows.h"

int main() {

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	MyVector<int> vec = {1, 2};
	try {
		MyVector<int> vec1(10);
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	
	//vec1.push_back(20);
	MyVector<int> vec3;
	vec3.push_back(206);
	vec3.push_back(30);
	vec3.push_back(50);
	vec3.push_back(60);
	try {
		std::cout << vec3.at(2) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	
	MyVector<int> vec4(vec3);
	std::cout << vec3.size() <<  std::endl;
	std::cout << vec3.capacity() <<  std::endl;
	return 0;
}