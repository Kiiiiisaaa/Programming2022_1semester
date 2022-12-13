// Используемые библиотеки
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Для возведения в степенб

// Заголовочный файл
#include "Header.h"

double get_min(int arr[SORTINGS_NUM]) {
	// Получение минимального значения из массива, где SORTINGS_NUM элементов
	double min = arr[0];
	for (int i = 0; i < SORTINGS_NUM; i++) if (min > arr[i]) min = arr[i];
	if (min == 0) min = 0.00001;
	return min;
}
double get_min_by_ptr(int* arr, int length) {
	// Получение минимального значения из массива по адрессу arr с длинной length
	int min = arr[0];
	for (int i = 0; i < length; i++) if (min > arr[i]) min = arr[i];
	if (min == 0) return 0.00001;
	return (double)min;
}

void sorts_comparison(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS)) {
	// Сравнение сортировок

	// Очистка консоли
	system("cls"); 

	// Записываем входной массив в файл input.txt
	write_out_in_file(nums, dir, "input.txt\0");

	printf("========================================== Cравнение сортировок ============================================");
	
	// Объявление переменных
	int times[SORTINGS_NUM];       // Время работы сортировок
	int swaps[SORTINGS_NUM];       // Перестановок в результате работы сортировок
	int comparisons[SORTINGS_NUM]; // Сравнений в результате работы сортировок

	for (int i = 0; i < SORTINGS_NUM; i++) {
		// Сбор статистики

		// Получаем неотсортированный массив, который 
		// мы записали заранее, из файла input.txt
		get_nums_from_file(&nums, dir);

		// Получаем данные
		STATS current_func_stats = sortings[i](nums);

		// Сохраняем данные в соответсвующие массивы
		times[i] = current_func_stats.time;
		swaps[i] = current_func_stats.swaps;
		comparisons[i] = current_func_stats.comparisons;
	}

	// Объявление переменных
	double delta_times[SORTINGS_NUM];       // Замедление
	double delta_swaps[SORTINGS_NUM];       // Увеличение числа перестановок
	double delta_comparisons[SORTINGS_NUM]; // Увеличение числа сравнений

	for (int i = 0; i < SORTINGS_NUM; i++) {
		// Рассчет замедления и увеличений чисел перестановок и сравнений
		delta_times[i] = times[i] / get_min(times);
		delta_swaps[i] = swaps[i] / get_min(swaps);
		delta_comparisons[i] = comparisons[i] / get_min(comparisons);
	}

	// Вывод таблицы с результатами
	printf("\n\n \t\t\t\t\t\t\t\tИзменение\t\t\tИзменение");
	printf("\n \t\t\t\t\t\tКоличество\tчисла\t\tКоличество\tчисла");
	printf("\n Сортировка\t\tВремя\tЗамедление\tперестановок\tперестановок\tсравнений\tсравнений");
	printf("\n============================================================================================================");
	for (int i = 0; i < SORTINGS_NUM; i++) printf("\n %16s %8d %11.2lf %17d %15.2lf %14d %13.2lf", sortings_names[i],  times[i], delta_times[i], swaps[i], delta_swaps[i], comparisons[i], delta_comparisons[i]);
	
	// Не обновлять вкладку пока не нажата клавиша
	printf("\n\n ");
	system("pause");
}

void rand_gen(NUMS* nums, int length) {
	// Генерируем случайный массив задаеной длины
	int* temp = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) temp[i] = rand() % 999 + 1;
	(*nums).nums = temp;
	(*nums).length = length;
}

void efficiency(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS)) {
	// Вкладка "Эффективность"
	
	// Очищаем консоль
	system("cls");

	// Выводим список доступных сортировок
	printf(" Доступные сортировки: ");
	for (int i = 0; i < SORTINGS_NUM; i++) printf("\n %d. %s", i + 1, sortings_names[i]);

	// Предлагаем выбрать сортировку
	int choose = 0;
	while (choose < 1 || choose > SORTINGS_NUM) {
		printf("\n\n Выберите сортировку: ");
		scanf_s("%d", &choose);
	}
	choose--;

	// Предлагаем задать количество замеров
	int tests_num = 0;
	while (!(tests_num >= 1)) {
		printf("\n Введите количество замеров: ");
		scanf_s("%d", &tests_num);
	}

	// Предлагаем ввести размеры рассматриваемых массивов, сохраняем в lengths
	printf(" Введите количества элементов в %d массивах: ", tests_num);
	int* lengths = (int*)malloc(sizeof(int) * tests_num);
	for (int i = 0; i < tests_num; i++) scanf_s("%d", &lengths[i]);

	// Инициализация массивов со временами работы и соотвеетсвующими замедлениями
	int* times = (int*)malloc(sizeof(int) * tests_num);
	double* delta_times = (double*)malloc(sizeof(double) * tests_num);

	// Сохранение времен работы
	for (int i = 0; i < tests_num; i++) {
		rand_gen(&nums, lengths[i]);
		STATS result = sortings[choose](nums);
		if (times != NULL) times[i] = (int)result.time;
	}

	// Расчет замедлений
	for (int i = 0; i < tests_num; i++) delta_times[i] = times[i] / get_min_by_ptr(times, tests_num);

	// Вывод таблицы результатов
	printf("\n\n");
	printf(" Размер массива\t  Время работы\tЗамедление");
	for (int i = 0; i < tests_num; i++) printf("\n %14d %14d %11.3lf", lengths[i], times[i], delta_times[i]);
	printf("\n\n ");
	system("pause");
}