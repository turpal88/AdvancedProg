#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void move_vectors(std::vector<T> &lhs, std::vector<T> &rhs) {
	rhs = std::move(lhs);
}

template<typename T>
void print_vector(const std::vector<T> vec) {
	std::for_each(vec.begin(), vec.end(), [](const T &n) {
		std::cout << n << " ";
		});
	std::cout << std::endl;
}

int main() {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	std::cout << " vector\"one\": ";
	print_vector(one);
	std::cout << " vector\"two\": ";
	print_vector(two);
	move_vectors(one, two);
	std::cout << std::endl;
	std::cout << " vector\"one\": ";
	print_vector(one);
	std::cout << " vector\"two\": ";
	print_vector(two);
	
	return 0;
}