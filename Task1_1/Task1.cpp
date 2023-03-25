#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<int> Vec = {4, 7, 9, 14, 12};
    std::cout << "Входные данные: ";
    std::for_each(Vec.begin(), Vec.end(), [](int n){std::cout << n << " ";}); // вектор выводится на печать

    std::cout << std::endl;

    std::for_each(Vec.begin(), Vec.end(), [](int &n){ // согласно заданию нечетные эелементы вектора умножаются на 3
        if(n % 2 != 0 || n == 1) n *= 3;
    });

    std::cout << "Выходные данные: ";
    std::for_each(Vec.begin(), Vec.end(), [](int n){std::cout << n << " ";}); //вектор снова выводится на печать

    return 0;
}
