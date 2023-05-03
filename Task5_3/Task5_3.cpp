#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>


class Functor {
public:
	Functor() : sum(0), count(0) {}
	void operator()(int n) {
		if (n % 3 == 0) sum += n;
		count++;
	}
	int get_sum() {
		return sum;
	}
	int get_count() {
		return count;
	}
private:
	int sum;
	int count;

};



int main() {
	std::vector<int> Vec;
	for (int i = 1; i < 15; i++) Vec.push_back(i);
	Functor f;
	std::cout << "[IN]: ";
	std::for_each(Vec.begin(), Vec.end(), [](int n) {std::cout << n << " "; });
	std::cout << std::endl;
	f = std::for_each(Vec.begin(), Vec.end(), f);
	std::cout << "[OUT]: get_sum() = " << f.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << f.get_count() << std::endl;
	return 0;
}