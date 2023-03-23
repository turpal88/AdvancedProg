#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int a;
    std::vector<int> Vec = {4, 7, 9, 14, 12};
    std::cout << "Входные данные: ";
    std::for_each(Vec.begin(), Vec.end(), [](int n){std::cout << n << " ";});
    std::cout << std::endl;
    std::cout << "Выходные данные: ";
    std::for_each(Vec.begin(), Vec.end(), [](int n){
       if(n % 2 != 0 || n == 1) std::cout << n * 3 << " ";
       else std::cout << n << " ";


    });
    return 0;
}
