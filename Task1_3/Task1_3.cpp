
#include <iostream>
#include <vector>
#include <variant>
#include <algorithm>
#include <functional>
#include <cmath>


double get_sin(double x){
    return sin(x);

}
double get_cos(double x){
    return cos(x);

}
double get_tan(double x){

    return tan(x);
}
double get_cotan(double x){

    return 1 / tan(x);
}




int main()
{
    std::function<double(double)> get_math_operation[4] = {get_sin, get_cos, get_tan, get_cotan};

    std::vector<std::string> Vec = {"30 * 3.1415926 / 180", "60 * 3.1415926 / 180", "90 * 3.1415926 / 180"};
    std::vector<double> tempVec = {};
    std::cout << "[Входные данные]: " << std::endl;
for(int i = 0; i < Vec.size(); i++){
std::cout << Vec.at(0);
if(i < Vec.size() - 1) std::cout << ", "; else std::cout << std::endl;
}
    std::for_each(Vec.begin(), Vec.end(), [&tempVec](std::string &n){

            std::string str = "";
            double temp = 0.0;
           for(char i : n){
               if(i != '*' && i != '/' && i != ' ') str += i;
               else if(i == ' ') continue;
               else if(i == '*') {
                   temp = std::atof(str.c_str());
                   str = "";
               }else if(i == '/') {
                   temp *= std::atof(str.c_str());
                   str = "";

               }

           }
           temp /= std::atof(str.c_str());
           tempVec.push_back(temp);
            //std::cout << temp << " ";




    });
std::cout << "[Выходные данные]: " << std::endl;
for(auto n : tempVec){
    std::cout << n << ": ";
for(int m = 0; m < 4; m ++){
    if(m == 0) std::cout << "sin: ";
    if(m == 1) std::cout << "cos: ";
    if(m == 2) std::cout << "tan: ";
    if(m == 3) std::cout << "cotan: ";
    std::cout << get_math_operation[m](n);
    if(m < 3) std::cout << " "; else std::cout << std::endl;
}
}

    return 0;
}
