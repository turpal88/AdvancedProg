#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>
#include <ctime>
#include <any>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    std::variant a = get_variant();
    if(std::holds_alternative<int>(a)) std::cout << std::get<int>(a) * 2 << std::endl;
    else if(std::holds_alternative<std::string>(a)) std::cout << std::get<std::string>(a) << std::endl;
    else {
        std::for_each(std::get<std::vector<int>>(a).begin(), std::get<std::vector<int>>(a).end(), [](int n) {std::cout << n << " ";});
    }
    return 0;
}


