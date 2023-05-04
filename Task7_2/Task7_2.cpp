#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>





template <typename Value_type>
void print_container(Value_type& container) {
	
	auto it = container.begin();
	for (auto i = it; i != container.end(); i++) {
		if (i != --container.end()) {
			std::cout << *i << ", ";
		}
		else std::cout << *i << std::endl;
	}
	
	//for (const auto it : container) std::cout << it;
}

int main() {

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };

	std::cout << "test_set on print: ";
	print_container(test_set);
	std::cout << "test_list on print: ";
	print_container(test_list);
	std::cout << "test_vector on print: ";
	print_container(test_vector);

	return 0;
}