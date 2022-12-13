// Используемые библиотеки
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// Заголовочный файл
#include "Header.h"


int is_sorted(NUMS nums) {
	// Проверка, отсортирован ли массив
	for (int i = 1; i < nums.length; i++) if (nums.nums[i - 1] > nums.nums[i]) return 0;
	return 1;
}

void write_out(NUMS nums) {
	// Вывести массив
	printf("\n {");
	for (int i = 0; i < nums.length; i++) printf(" %d ", nums.nums[i]);
	printf("}\n");
}

void swap(NUMS nums, int i, int j) {
	// Поменять местами i-ый и j-ый элементы в nums
	int tmp = nums.nums[i];
	nums.nums[i] = nums.nums[j];
	nums.nums[j] = tmp;
}

STATS bubble_sort(NUMS nums) { 
	// Сортировка пузырьком
	STATS result = { clock(), 0, 0 };
	for (int j = 0; j < nums.length - 1; j++) {
		int fl = 1;
		result.comparisons++;
		for (int i = 0; i < nums.length - j - 1; i++) {
			result.comparisons += 2;
			if (nums.nums[i] > nums.nums[i + 1]) {
				swap(nums, i, i + 1);
				result.swaps++;
				fl = 0;
			}

		}
		if (fl) break;
	}
	result.time = clock() - result.time;
	return result;
}

STATS shaker_sort(NUMS nums) {
	// Шейкерная сортировка
	STATS result = { clock(), 0, 0 };
	int left = 0, right = nums.length - 1;
	int flag = 1;  

	while ((left < right) && flag > 0)
	{	
		result.comparisons += 2;
		flag = 0;
		for (int i = left; i < right; i++) 
		{	
			result.comparisons += 2;
			if (nums.nums[i] > nums.nums[i + 1]) 
			{          
				swap(nums, i, i + 1);
				result.swaps++;
				flag = 1;
			}
		}
		right--; 
		for (int i = right; i > left; i--) 
		{
			result.comparisons += 2;
			if (nums.nums[i - 1] > nums.nums[i]) 
			{
				swap(nums, i, i - 1);
				result.swaps++;
				flag = 1;
			}
		}
		left++;
	}
	result.time = clock() - result.time;

	return result;
}


STATS selection_sort(NUMS nums) {
	// Сортировка выбором
	STATS result = { clock(), 0, 0 };
	int min_value;

	for (int i = 0; i < nums.length - 1; i++) {
		min_value = i;
		for (int j = i + 1; j < nums.length; j++) {
			if (nums.nums[min_value] > nums.nums[j]) {
				result.comparisons += 3;
				min_value = j;
			}
		}
		swap(nums, i, min_value);
		result.swaps++;
	}
	result.time = clock() - result.time;
	return result;
}

long sedgewick(int s) {
	// Вычисление s-ого элемента последовательности Седжвика
	int result;
	if (s % 2 == 0) result = 9 * pow(2, s) - 9 * pow(2, s / 2) + 1;
	else result = 8 * pow(2, s) - 6 * pow(2, (s + 1) / 2) + 1;
	return result;
}

int count_max(int max) {
	// Вычисление индекса максимального элемента последовательности Седжвика, не превосходящего max
	int i = 0;
	while (sedgewick(i + 1) < max) {
		i++;
	}
	return i;
}

STATS shell_sort(NUMS nums) {
	// Сортировка Шелла по последовательности Седжвика
	STATS result = { clock(), 0, 0 };
	// Rearrange elements at each n/2, n/4, n/8, ... intervals
	int m = count_max(nums.length); // Порядковый номер максимального элемента последовательности
									// Седжвика, не превосходящий длину массива
	result.comparisons += m;
	for (int k = m; k > -1; k --) {
		result.comparisons++;
		int interval = sedgewick(k); // Текущий интервал из пос-ти Седжвика
		for (int i = interval; i < nums.length; i += 1) {
			result.comparisons++;
			int temp = nums.nums[i];
			int j;
			for (j = i; j >= interval && nums.nums[j - interval] > temp; j -= interval) {
				nums.nums[j] = nums.nums[j - interval];
				result.comparisons += 2;
				result.swaps++;
			}
			nums.nums[j] = temp;
			result.swaps++;
		}
	}
	result.time = clock() - result.time;
	return result;
}


void sort_menu_by_ptr(NUMS nums, STATS (func)(NUMS), char path[100], char* name) {
	// Вкладка сортировки
	
	// Очищаем консоль
	system("cls");

	// Выводим название сортировки
	printf(" %s\n", name);

	// Переменная для сохранения статистики
	STATS stats;
	
	// Вывод массива 
	if (nums.length <= 20) {
		printf("\n Массив до сортировки:");
		write_out(nums);
	}
	else { 
		write_out_in_file(nums, path, "input.txt");
		printf("\n В несортированном массиве более 20 элементов. Он выведен в файл input.txt"); 
	}

	// Вызов соответствующей функции сортировки
	stats = func(nums);
	
	// Вывод массива
	if (nums.length <= 20) {
		printf("\n Массив после сортировки");
		write_out(nums);
	}
	else {
		write_out_in_file(nums, path, "output.txt");
		printf("\n В отсортированном массиве более 20 элементов. Он выведен в файл output.txt");
	}

	// Вывод статистики
	printf("\n\n Время: %d", stats.time);
	printf("\n Перестановок: %lld", stats.swaps);
	printf("\n Сравнений: %lld", stats.comparisons);

	// Не обновляем консоль, пока не нажата клавиша
	printf("\n\n ");
	system("pause");
}