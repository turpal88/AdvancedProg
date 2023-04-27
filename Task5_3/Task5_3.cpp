#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

class get_sum {

public:
	get_sum(std::vector<int> Vec) : Vec(Vec) {}
	int operator()() {
		int sum = 0;
		for (auto i : Vec) if(i % 3 == 0) sum += i;
		return sum;
	}

private:
	std::vector<int> Vec;
	
};

class get_count {

public:
	get_count(std::vector<int> Vec) : Vec(Vec) {}
	int operator()() {
		int sum = 0;
		for (auto i : Vec) if (i % 3 == 0) sum++;
		return sum;
	}

private:
	std::vector<int> Vec;

};
int main() {
	std::vector<int> Vec;
	for (int i = 1; i < 15; i++) Vec.push_back(i);
	get_sum Get_sum(Vec);
	get_count Get_count(Vec);
	std::cout << "[IN]: ";
	std::for_each(Vec.begin(), Vec.end(), [](int n) {std::cout << n << " "; });
	std::cout << std::endl;
	std::cout << "[OUT]: get_sum() = " << Get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << Get_count() << std::endl;
	return 0;
}