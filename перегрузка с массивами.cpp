﻿//Разработать программу в соответствии с объектно - ориентированной
//технологией.
//Класс: Одномерный массив вещественных чисел.
//	Поля : количество элементов, элементы.
//	Реализовать конструктор для выделения памяти.
//	Реализовать методы :
// нахождения минимального положительного элемента массива;
// сортировки элементов массива по убыванию суммы цифр их целой
//части.
//Перегрузить оператор[] так, чтобы была возможность из main - функции
//присваивать значение элементам массива класса.
//Перегрузить оператор = так, чтобы записав выражение Object = Object2
//массив объекта Object стал идентичными массиву объекта Object2 и по
//количеству ячеек массива и по значениям, которые хранят ячейки массива.
//Осуществить перегрузку операторов ввода и вывода.
//Перегрузить оператор « / » так, чтобы с двумя операндами типа массив он
//выполнял операцию деления двух массивов поэлементно.
//Перегрузить оператор « += » так, чтобы с операндами типа массив и типа
//int он выполнял операцию сложения каждого элемента массива и числа.
//Перегрузить унарный оператор «++» так, чтобы он умножал каждый
//элемент массива на 10.
//Перегрузить оператор « *= » так, чтобы с операндами типа массив и типа
//int он выполнял умножение каждого элемента на заданное число.
//Создать объекты класса массив.Вывести их на экран.
//Продемонстрировать работу всех реализованных методов.Результаты
//работы выводить на экран с пояснениями.

#include <iostream>

using namespace std;
int func2(double a) {
	int elem = floor(a);
	int c = 0;
	int summ = 0;
	while (elem != 0)
	{
		c = elem % 10;
		elem /= 10;
		summ += c;
	}
	return summ;
}


class Array_ {
private:
	int amount_elements;
	double elem_arr;
	double* arr = new double[amount_elements];
public:
	Array_(int memory, double elem_arr_ = 0) {
		amount_elements = memory;
		arr = new double[amount_elements];
	}

	void create_array() {
		int j = 0;
		cout << "Введите элементы в массив: " << endl;
		for (int i = 0; i < amount_elements; i++)
		{	
			elem_arr = 0;
			cin >> elem_arr;
			arr[j] = elem_arr;
			j++;
		}
	}

	void find_min_elem() {
		double min_ = 1000000;
		for (int i = 0; i < amount_elements; i++) {
			if (arr[i] < min_ && arr[i] > 0) {
				min_ = arr[i];
			}
		}
		cout << endl;
		cout << "Минимальный элемент в массиве: " << min_ << endl;
		
	}

	void sort() {
		int* arr1 = new int[amount_elements];
		int* new_arr = new int[amount_elements];
		int j_ = 0;
		int p = 0;
		int a = 0;
		int min = 0;

		for (int i = 0; i < amount_elements; i++)
		{
			arr1[j_] = func2(arr[i]);
			j_++;
		}
		for (int i = 0; i < amount_elements; i++)
		{

			int c = 0;

			for (int j = 0; j < amount_elements; j++) if (arr1[j] < arr1[i]) c++;

			for (int j = 0; j < i; j++) if (arr1[j] == arr1[i]) c++;

			new_arr[c] = arr1[i];

		}

		cout << endl;
		cout << "Массив до этого: " << endl;
		for (int i = 0; i < amount_elements; i++) {
			cout << arr[i];
			cout << " ";
		}
		cout << endl;
		cout << "Отсортированный массив: " << endl;
		for (int i = amount_elements - 1; i >= 0; i--) {
			cout << new_arr[i];
			cout << " ";
		}
	}

	int get_amount_elements() {
		return amount_elements;
	}

	void print_array() {
		cout << endl;
		cout << "Выбрана функция для вывода исходного массива: " << endl;
		for (int i = 0; i < amount_elements; i++) {
			cout << arr[i] << " ";
		}
	}

	double &operator[](int i) {
		return arr[i];
	};

	Array_& operator= (const Array_& array_) {
		if (this == &array_) {
			return *this;
		}
		arr = array_.arr;
		return *this;
	};

	friend std::ostream& operator<< (std::ostream& out, const Array_& array_);
	friend std::istream& operator>> (std::istream& in, Array_& array_);

	friend Array_ operator/ (Array_& array__, Array_& array_);

	friend Array_ operator+= (Array_& array__, int a);

	Array_& operator++ () {
		
		
		for (int i = 0; i < amount_elements; i++) {
			arr[i] *= 10;
		}
		return *this;
	}

	friend Array_ operator*= (Array_& array__, int a);

};

std::ostream& operator<< (std::ostream& out, const Array_& array_) {
	out << "Кол-во элементов: " << array_.amount_elements << endl;
	out << "Массив : " << endl;
	for (int i = 0; i < array_.amount_elements; i++) {
		out << array_.arr[i] << " ";
	}
	return out;
}

std::istream& operator>> (std::istream& in, Array_& array_) {
	in >> array_.amount_elements;
	return in;
}

Array_ operator/ (Array_& array__, Array_& array_){
	for (int i = 0; i < array_.amount_elements; i++) {
		array__.arr[i] /= array_.arr[i];
	}
	return array__;
};

Array_ operator+= (Array_& array__, int a) {
	for (int i = 0; i < array__.amount_elements; i++) {
		array__.arr[i] += a;
	}
	return array__;
}

Array_ operator*= (Array_& array__, int a) {
	for (int i = 0; i < array__.amount_elements; i++) {
		array__.arr[i] *= a;
	}
	return array__;
}


int main()
{
	setlocale(LC_ALL, "ru");

	Array_ array_(5);
	cin >> array_; // перегрузка оператора ввода, ввожу кол-во элементов в массиве
	array_.create_array();
	Array_ array_2(array_.get_amount_elements());
	array_2.create_array();
	array_ = array_ / array_2; // перегрузка оператора /, первый экземпляр класса поделил на второй
	array_.print_array();
	array_.find_min_elem();
	array_.sort();
	array_[2] = 12345; // перегрузка оператора [], 2 (вообще 3, но не важно) элементу из массива присвоил значение 12345
	array_.print_array();
	Array_ array_3(array_.get_amount_elements());
	array_3 = array_; // перегрузка оператора =, третему экземпляру класса присвоил массив из первго
	array_3 *= 4; // перегрузка оператора *=
	cout << endl;
	cout << "Третему экземпляру класса присвоил первый: ";
	array_3.print_array();
	cout << endl;
	cout << array_; // перегрузка оператора вывода, вывожу кол-во элементов в массиве первого экземпляра класса и сам массив
	cout << endl;
	array_2 += 100; // перегрузка оператора +=, второму экземпляру класса добавил и крч присвоил 100
	cout << array_2;
	//array_2++;
	cout << endl;
	++array_2; // перегрузка оператора ++
	cout << array_2; 
	
	

}