#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
#//include <utility>
//#include <string_view>

class big_integer{

public:
	big_integer() : s(" "), value(0) {}
	big_integer(std::string s) {
		this->s = s;
		try {
			value = std::stoll(s);
		}
		catch (std::invalid_argument& e) {
			std::cout << "Невозможно преобразовать введенное число в тип long long!";
		}
	}
	big_integer(big_integer& right) = delete; //запрет на конструктор копирования
	big_integer& operator=(const std::string& right) = delete; // запрет на оператор присваивания
	big_integer& operator=(big_integer&& right) noexcept { // перемещающий оператор присваивания
		std::swap(this->value, right.value);
		return *this;
	}
	big_integer(big_integer&& right) noexcept : value(std::exchange(right.value, static_cast<long long>(0))) {} // конструктор перемещения

	big_integer operator+(big_integer& right) {
		long long temp_value = this->value + right.value;
		big_integer temp(std::to_string(temp_value));
		//this->value += right.value;
		//big_integer temp = std::move(*this);
		//temp.set_value(this->get_value() + right.get_value());
		return temp;

	}
	big_integer& operator*(int&& a) {
		this->value *= a;
		return *this;
	}
	
	long long get_value() {
		return value;
	}
	
	
private:
	std::string s;
	long long value;
};

std::ostream& operator << (std::ostream& os, big_integer &Big_integer) {
	return os << Big_integer.get_value() << std::endl;
}

int main() {
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << result;

	return 0;
}