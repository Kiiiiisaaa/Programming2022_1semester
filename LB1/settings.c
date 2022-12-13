// Используемые библиотеки
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Заголовочный файл
#include "Header.h"



void show_current_array(NUMS nums, char dir[100]) {
	// Вкладка показа текущего массива

	// Очищаем консоль
	system("cls");
	if (nums.length <= 20) {

		// Если в массиве <= 20 элементов - вывести в консоль
		printf(" Текущий массив: \n");
		for (int i = 0; i < nums.length; i++) printf(" %d ", nums.nums[i]);
	}
	else {
		// Иначе - вывести в output.txt текущей рабочей директории 
		printf(" Текущий массив содержит более 20 элементов. Массив был сохранен в файл output.txt рабочей директории");
		write_out_in_file(nums, dir, "output.txt\0");
	}

	// Не обновляем консоль, пока не нажата клавиша
	printf("\n ");
	system("pause");
}

void set_path(char path[100]) {
	// Изменение рабочей директории

	// Очищаем консоль
	system("cls");

	// Вывод текущей директории и предложение ввести новую
	printf(" Текущая директория: %s\n", path);
	printf(" Введите новую директорию: ");

	// Инициализация переменных
	int i = 0; // Индекс для ввода
	char c;    // Символьная переменная для сохранения введенного символа

	// Непосредственно ввод
	while ((c = getchar()) != '\n') {
		path[i++] = c;
	}

	// Установка символа конца строки
	path[i] = '\0';

	// Не обновляем консоль, пока не нажата клавиша
	printf("\n Успешно!\n ");
	system("pause");
}

void get_nums_from_file_menu(NUMS* nums, char dir[100]) {
	// Вкладка "Прочитать из файла"

	// Очищаем экран
	system("cls");

	// Получаем числа из файла
	get_nums_from_file(nums, dir);

	// Не обновляем консоль, пока не нажата клавиша
	printf(" Массив успешно прочтен! Чисел в массиве: %d\n ", (*nums).length);
	system("pause");
}

void rand_gen_menu(NUMS* nums) {
	// Вкладка "Сгенерировать случайно"

	// Инициализация перемнных
	int is_correct = 0, length = -1, low = 0, high = 100;
	// Вводим количество элементов массива
	while (!is_correct) {
		system("cls");
		printf(" Введите количество элементов в массиве: ");
		scanf_s("%d", &length);
		if (length > 0) is_correct = 1;
	}
	// Ввод минимального допустимого значения
	printf("\n Введите минимальное  допустимое значение в массиве: ");
	scanf_s("%d", &low);

	// Ввод макимального допустимого значения
	printf("\n Введите максимальное допустимое значение в массиве: ");
	scanf_s("%d", &high);

	// Делаем псевдослучайные числа отличными от тех, что были в предыдущем запуске программмы
	srand(time(NULL));

	// Создаем указатель на массив для чисел
	int* tmp = (int*)malloc(sizeof(int) * length);

	// Заполняем случайными числами из заданного пользователем диапозона
	for (int i = 0; i < length; i++) tmp[i] = rand() % (high - low + 1) + low;

	// Сохраняем сгенерированный массив в nums
	(*nums).nums = tmp;
	(*nums).length = length;

	// Не обновляем консоль, пока не нажата клавиша
	printf("\n Массив успешно сгенерирован!\n ");
	system("pause");
}

void users_array(NUMS* nums) {
	// Вкладка "Задать вручную"
	
	// Считываем длину массива
	int length = 0;
	while (length < 1) {
		system("cls");
		printf(" Введите количество элементов: ");
		scanf_s("%d", &length);
	}

	// Создаем указатель на массив
	int* tmp = (int*)malloc(sizeof(int) * length);

	// Запрашиваем ввод чисел
	printf(" Введите элементы массива: ");
	for (int i = 0; i < length; i++) scanf_s("%d", &tmp[i]);

	// Сохраняем результат в nums
	(*nums).length = length;
	(*nums).nums = tmp;

	// Не обновляем консоль, пока не нажата клавиша
	printf("\n Успешно!\n ");
	system("pause");
}