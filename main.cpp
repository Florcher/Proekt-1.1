#include <iostream>
#include "proekt.h"
#include <fstream>
#include <string>


object** input_of_file(int& size_of_array_of_object);
object** input_of_console(int& size_of_array_of_object);



int main() {

	setlocale(LC_ALL, "ru");


	object** (*function_of_input)(int&);

	int metka;

	std::cout << "Введите 1,чтобы прочитать данные из файла. Введите 2, чтобы прочитать данные из консоли.\n";
	std::cin >> metka;

	if (metka == 1) {
		function_of_input = input_of_file;
	}
	else {
		function_of_input = input_of_console;
	}


	int size;
	object** obj = function_of_input(size);
	




	for (int i = 0; i < size; i++) {
		obj[i]->print();
	}

	





	
	return 0;
}



object** input_of_file(int& size_of_array_of_object) {

	std::string path = "file.txt";

	std::ifstream fin;

	fin.open(path);

	int count_of_object;
	fin >> count_of_object;

	size_of_array_of_object = count_of_object;

	std::string* arr_of_name_object = new std::string[count_of_object];
	int* arr_of_index_of_object = new int[count_of_object];
	object** arr_of_object = new object * [count_of_object];


	for (int i = 0; i < count_of_object; i++) {

		fin >> arr_of_name_object[i];
		fin >> arr_of_index_of_object[i];

		if (arr_of_index_of_object[i] == 0) {

			Point start, end;
			fin >> start.x;
			fin >> start.y;
			fin >> end.x;
			fin >> end.y;

			arr_of_object[i] = new  Line(arr_of_name_object[i], 0, start, end);
		}
		else {

			if (arr_of_index_of_object[i] == 1) {

				Point AB, BC, CD, DA;

				fin >> AB.x;
				fin >> AB.y;
				fin >> BC.x;
				fin >> BC.y;
				fin >> CD.x;
				fin >> CD.y;
				fin >> DA.x;
				fin >> DA.y;

				arr_of_object[i] = new Rectangle(arr_of_name_object[i], 1, AB, BC, CD, DA);

			}

		}

	}

	fin.close();

	delete[] arr_of_name_object;
	delete[] arr_of_index_of_object;


	return arr_of_object;


}


object** input_of_console(int& size_of_array_of_object) {


	int count_object;
	std::cout << "Введите колличесвто объектов и объекты в виде:\n ";
	std::cout << "Коилчесвто объектов:\n ";
	std::cout << "Имя объекта\n ";
	std::cout << "Уникальный id объекта\n ";
	std::cout << "Характеристики объектов(их координаты)\n ";
	std::cin >> count_object;

	size_of_array_of_object = count_object;

	std::string* arr_of_name_object = new std::string[count_object];
	int* arr_of_index_of_object = new int[count_object];
	object** arr_of_object = new object * [count_object];


	for (int i = 0; i < count_object; i++) {

		std::cin >> arr_of_name_object[i];
		std::cin >> arr_of_index_of_object[i];

		if (arr_of_index_of_object[i] == 0) {

			Point start, end;
			std::cin >> start.x;
			std::cin >> start.y;
			std::cin >> end.x;
			std::cin >> end.y;

			arr_of_object[i] = new  Line(arr_of_name_object[i], 0, start, end);
		}
		else {

			if (arr_of_index_of_object[i] == 1) {

				Point AB, BC, CD, DA;

				std::cin >> AB.x;
				std::cin >> AB.y;
				std::cin >> BC.x;
				std::cin >> BC.y;
				std::cin >> CD.x;
				std::cin >> CD.y;
				std::cin >> DA.x;
				std::cin >> DA.y;

				arr_of_object[i] = new Rectangle(arr_of_name_object[i], 1, AB, BC, CD, DA);

			}

		}

	}


	std::string path = "file1.txt";

	std::ofstream fout;
	fout.open(path, std::ofstream::app);

	for (int i = 0; i < count_object; i++) {
		fout.write((char*)&arr_of_object[i], sizeof(*arr_of_object));
	}


	return arr_of_object;

	delete[] arr_of_name_object;
	delete[] arr_of_index_of_object;


}