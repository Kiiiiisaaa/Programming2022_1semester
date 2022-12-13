// Используемые библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/stat.h"

// Заголовочный файл
#include "Header.h"


void get_nums_from_file(NUMS* result, char dir[100]) {
	// Получаем числа из файла input.txt директории dir в структуру nums

	// Получаем адрес файла для чтения
	char filename[100] = "input.txt";
	char filepath[200];
	strcpy_s(filepath, sizeof filepath, dir);
	strncat_s(filepath, 100, filename, 100);

	(*result).length = -1;
	
	// Объявление переменных 
	FILE* input_file = NULL;  // Для файла
	errno_t error;            // Для возможной ошибки
	int size;                 // Количество чисел в файле
	int* mass = NULL;         // Временный массив для сохранения прочтенных чисел

	// Открываем файл
	error = fopen_s(&input_file, filepath, "r+"); // r – read, w - write

	// Проверка, существует ли файл
	if (input_file == NULL) {
		printf("\n  Файл не существует! Создайте его и запустите программу вновь!\n  ");
		return;
	}
	else {
		// Если файл существуе

		// Проверяем, не пуст ли файл
		if (fscanf_s(input_file, "%d", &size) != 1) {
			printf("\n  Файл с элементами массива пуст! Заполните его и запустите программу вновь!\n  ");
			return;
		}
		// Если не пуст
		// Инициализируем массив для чисел
		mass = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++) {
			// Считываем числа
			if (fscanf_s(input_file, "%d", &mass[i]) != 1) {
				return;
			}
		}

		// Закрываем файл
		fclose(input_file);
	}

	// Подготавливаем структуру, чтобы вернуть ее
	(*result).length = size;
	(*result).nums = mass;
	return;
}

void write_out_in_file(NUMS nums, char dir[100], char filename[100]) {
	// Записываем числа nums в файл filename директории dir

	// Получаем адресс файла для записи
	char filepath[200];
	strcpy_s(filepath, sizeof filepath, dir);
	strncat_s(filepath, 100, filename, 100);

	// Инициализация переменных
	FILE* output_file = NULL;  // Для файла
	errno_t error;             // Для возможной ошибки

	// Открываем файл
	error = fopen_s(&output_file, filepath, "w+"); // r – read, w - write

	// Проверка, существует ли файл
	if (output_file == NULL) {
		printf("\n\n Ошибка! Файл %s не найден!", filename);
		return;
	}
	else {
		// Если существует, записываем числа в этот файл
		fprintf_s(output_file, "%d ", nums.length);
		for (int i = 0; i < nums.length; i++) {
			fprintf_s(output_file, "%d ", nums.nums[i]);
		}

		// Закрываем файл
		fclose(output_file);
	}
	return;
}
