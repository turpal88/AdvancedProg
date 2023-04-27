#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template<typename T>
void get_sqrt(T &x) { //шаблон для числовых типов
	x *= x;
}

template<typename T>
void get_sqrt(std::vector<T> &x) { //шаблон для векторов
	std::for_each(x.begin(), x.end(), [](T &x) 
		{
			x *= x;
		});
}
int main() {
	int a = 4;
	std::vector Vec = {-1, 4, 8};

	std::cout << "[IN]: " << a << std::endl;
	get_sqrt(a);
	std::cout << "[OUT]: " << a << std::endl;

	std::cout << "[IN]: ";
	for (int i = 0; i < Vec.size(); i++) {
		if (i < Vec.size() - 1) std::cout << Vec[i] << ", "; else std::cout << Vec[i] << std::endl;
	}

	get_sqrt(Vec);
		std::cout << "[OUT]: ";
		for (int i = 0; i < Vec.size(); i++) {
		if (i < Vec.size() - 1) std::cout << Vec[i] << ", "; else std::cout << Vec[i] << std::endl;
	}

	return 0;
}