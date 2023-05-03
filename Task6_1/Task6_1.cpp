#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include <algorithm>

int main() {

	std::string expression = "";
	std::multimap<char, std::string> expression_multimap = {}; //используется multimap, ключ - символ введенного выражения, 
																	//значение - не просмотрено (для подсчета количества символов в выражении)
																	//multimap потому что можно хранить неуникальные пары ключ-значение
	std::vector<std::pair<char, int>> symbol_and_its_count = {};
	std::cout << "[IN]: ";
	std::getline(std::cin, expression);
	for (auto i : expression) expression_multimap.insert({ i,  "not_seen" }); //переносим все символы из строки string в контейнер multimap
	for (auto i : expression_multimap) { //в цикле для каждого элемента контейнера проходим по всей введенной фразе и переносим ключ элемента контейнера в вектор
										//а потом еще и кол-во одинаковых ключей. Ключ - это символ в введенной строке. Просмотренные элементы контейнера помечаем что они просмотрены
		if (i.second == "not_seen") {
			auto range = expression_multimap.equal_range(i.first);
			int count = 0;
			for (auto& it = range.first; it != range.second; it++) {
				it->second = "seen";
				count++;
			} 
			symbol_and_its_count.push_back({ i.first, count });
			i.second = "seen";
		}
		std::sort(symbol_and_its_count.begin(), symbol_and_its_count.end(), [](const std::pair<char, int> first, const std::pair<char, int> second) {
			return first.second > second.second;
			});

		

		
	}

	std::cout << "[OUT]:" << std::endl;
	for (auto i : symbol_and_its_count) {
		std::cout << i.first << ": " << i.second << std::endl;
	}
	return 0;
}