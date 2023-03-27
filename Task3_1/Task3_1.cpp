#include <iostream>
#include <stdexcept>

class smart_array{

private:
    int* arr;
    int actual_size;
    int logical_size;
public:

    smart_array(int n){
        if(n <= 0) throw std::invalid_argument("Количество элементов массива некорректно!"); else this->actual_size = n;
        arr = new int[actual_size];
        logical_size = 0;

    }
    void add_element(int added_element){
        if(logical_size <= actual_size - 1){
            arr[logical_size] = added_element;
            logical_size++;

        } else throw std::out_of_range("Массив заполнен!");

    }

    int get_element(int index){
        if(index >= 0 && index <= actual_size - 1) return arr[index]; else throw std::out_of_range("Недопустимый индекс массива!");
    }

    ~smart_array(){
        delete [] arr;
    }
};

int main(){
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
