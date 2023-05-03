#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"


#define DIGIT_COUNT 7 //количество вводимых чисел

int main() {
	
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	
	
	std::vector <int> digit_vector; //вектор типа int
	std::string one_input_digit = " "; //в эту переменную сохраняется одно введенное число
	std::cout << "Вводите числа: " << std::endl;
	int digit_count = 0; //счетчик вводимых чисел
	while (digit_count != DIGIT_COUNT) { //вводим число, считываем его в переменную one_input_digit, затем пуш в вектор, преобразовав предварительно в int
		
		std::getline(std::cin, one_input_digit);
		try {
			digit_vector.push_back(std::stoi(one_input_digit));
		}
		
		catch (std::invalid_argument& e) { //выбрасывается исключение если введено не число
			std::cout << "Введено не число!" << std::endl;
			
			
		}
		
		
		digit_count++;
		
	}
	
	system("cls");
	std::cout << "[IN]:" << std::endl;
	std::for_each(digit_vector.begin(), digit_vector.end(), [](const int& n) { //вектор на печать
	std::cout << n << std::endl;
	});
	
	std::sort(digit_vector.begin(), digit_vector.end(), [](const int& a, const int& b) { //сортировка вектора по убыванию
		return a > b;
		});
	
	for (int i = 0; i < digit_vector.size() - 1; i++) {
		if (digit_vector[i] == digit_vector[i + 1]) {
			digit_vector.erase(digit_vector.begin() + i + 1); //удаление элементов вектора если они неуникальны
			i--;
		} 
	}

	std::cout << "[OUT]:" << std::endl;
	std::for_each(digit_vector.begin(), digit_vector.end(), [](int &n) { //вектор на печать
		std::cout << n << std::endl;
		});
	
	
	return 0;
}