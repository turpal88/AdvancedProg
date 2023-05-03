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
        for(int i = 0; i < actual_size; i++) arr[i] = 0;

    }
    void add_element(int added_element){
        if(logical_size <= actual_size - 1){
            arr[logical_size] = added_element;
            logical_size++;

        } else throw std::out_of_range("Массив заполнен!");

    }

    int get_element(int index) const{
        if(index >= 0 && index <= actual_size - 1) return arr[index]; else throw std::out_of_range("Недопустимый индекс массива!");
    }

    smart_array& operator=(smart_array& right){
        if (&right != this) {
            
                int* increased_arr = new int[right.actual_size];
                delete arr;
                this->arr = increased_arr;
                this->actual_size = right.actual_size;
                this->logical_size = right.logical_size;
                for (int i = 0; i < right.actual_size; i++) this->arr[i] = right.arr[i];
            

            
        }
        
        return *this;

    }

    void print_arr(){
        for(int i = 0; i < logical_size; i++){
            std::cout << arr[i];
            if(i < logical_size - 1) std::cout << " "; else std::cout << std::endl;
        }
    }


    smart_array(const smart_array& right) {
        this->actual_size = right.actual_size;
        this->logical_size = right.logical_size;
        this->arr = new int[this->actual_size];
        for(int i = 0; i < this->actual_size; i++) this->arr[i] = right.arr[i];
    }
   // smart_array& operator=(const smart_array&) = delete;

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

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr.print_arr();
        std::cout << std::endl;
        new_array.print_arr();
        std::cout << std::endl;

        smart_array arr3(5);
              
        arr = new_array;

        arr.print_arr();
        std::cout << std::endl;
        new_array.print_arr();
        std::cout << std::endl;

    }



    catch(const std::exception& ex){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
