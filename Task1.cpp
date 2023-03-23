#include <iostream>
#include <vector>


int main()
{
    int a;
    std::vector<int> Vec = {4, 7, 9, 14, 12};
    std::cout << "Входные данные: ";
    for(int el:Vec) std::cout << el << " ";
    return 0;
}
