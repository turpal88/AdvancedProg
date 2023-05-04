#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::vector<int>::const_iterator i = vec.cbegin();
	std::cout << "[IN]: ";
	while (i != vec.cend() - 1) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << *i << std::endl;

	std::sort(vec.begin(), vec.end(), [](const int& a, const int &b) {
		return a < b;
		});
	auto f = std::unique(vec.begin(), vec.end());
	vec.erase(f, vec.end());
	i = vec.cbegin();

	std::cout << "[OUT]: ";
	while (i != vec.cend() - 1) {
		std::cout << *i << " ";
		i++;
	}
	std::cout << *i << std::endl;

	return 0;
}