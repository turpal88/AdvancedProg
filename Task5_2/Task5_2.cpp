#include <iostream>

#include <windows.h>
template<typename T>
class matrix {
public:
	matrix(int x, int y) { //конструктор - инициализация кол-ва строк, столбцов, выделение памяти под двумерный массив - матрицу
		row_count = x;
		column_count = y;
		arr = new T*[row_count];
		for (int i = 0; i < row_count; i++) arr[i] = new T[column_count];
	}

	matrix& operator=(const matrix& right) { //перегрузка оператора присваивания
		if (right != this) {
			T** new_arr = new T * [right.row_count];
			for (int i = 0; i < right.row_count; i++) new_arr[i] = new T[right.column_count];
			for (int i = 0; i < this->row_count; i++) delete[] this->arr[i];
			delete[] this->arr;
			this->row_count = right.row_count;
			this->column_count = right.column_count;
			arr = new_arr;
			for (int i = 0; i < this->row_count; i++) {
				for (int j = 0; j < this->column_count; j++) {
					arr[i][j] = right[i][j];
				}
			}
			
		}
	}

	matrix(const matrix& right) { //конструктор копирования
		T** arr = new T * [right.row_count];
		for (int i = 0; i < right.row_count; i++) arr[i] = new T[right.column_count];
		for (int i = 0; i < this->row_count; i++) {
			for (int j = 0; j < this->column_count; j++) {
				arr[i][j] = right.arr[i][j];
			}
		}
	}

	T* operator[](int x){ //такая перегрузка оператора [] возвращает указатель на элемент типа T. Этот способ подсмотрел в гугле  и так и не понял как он работает.
							//так как при повторном вызове этого оператора (когда берем индекс столбца), у нас возвращается указатель на T, а на печать почему то выводится число а не его адрес
		
		return arr[x];
	}

	int Size() const {
		return row_count * column_count;
	}

	~matrix() {
		for (int i = 0; i < row_count; i++) delete[] arr[i];
		delete[] arr;
	}
private:
	int row_count = 0;
	int column_count = 0;
	T** arr = nullptr;
};

int main() {
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	matrix<int> Matrix(5, 6); //создается объект класса Matrix 5x6
	for (int i = 0; i < 5; i++) { //матрицу на печать
		for (int j = 0; j < 6; j++) {
			Matrix[i][j] = 7; //заполняется 7-ками
		}
	}
	matrix<int> Matrix2(Matrix);
	Matrix[0][3] = 8; //у любого элемента меняем значение
	
	for (int i = 0; i < 5; i++) { //снова матрицу на печать
		for (int j = 0; j < 6; j++) {
			std::cout << Matrix[i][j]; if (j < 5) std::cout << " "; else std::cout << std::endl;
			
		}
	}

	std::cout << std::endl;
	std::cout << "Размер массива: " << Matrix.Size() << std::endl;

	return 0;
}