#include <iostream>
#include "windows.h"
#include "MyUniquePtr.hpp"
//template<typename T>
class MyClass {

public:
	MyClass(int n) : n(n) {}
	int get_n() const {
		std::cout << "Я объект класса MyClass и я вернул значение поля n через метод get_n()" << std::endl;
		return n;
	}
private:
	int n;
};

void print_my_class(MyUniquePtr<MyClass>& my_unique_ptr) {
	MyClass temp = *my_unique_ptr;
	std::cout << temp.get_n() << std::endl;
}
int main() {
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	MyUniquePtr<MyClass> my_unique_ptr(new MyClass(10));
	print_my_class(my_unique_ptr);
	MyClass* temp = my_unique_ptr.release();
	std::cout << temp->get_n() << std::endl;

return 0;
}