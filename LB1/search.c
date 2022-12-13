// Используемые библиотеки
#include <stdlib.h>
#include <stdio.h>

// Заголовочный файл
#include "Header.h"

int check_is_sorted(NUMS nums) {
	// Проверка, отсортирован ли массив
	for (int i = 1; i < nums.length; i++) if (nums.nums[i - 1] > nums.nums[i]) return 0;
	return 1;
}

int naive(NUMS nums, int desired) {
	// Наивный поиск
	for (int i = 0; i < nums.length; i++) if (nums.nums[i] == desired) return i;
	return -1;
}

int binary(NUMS nums, int desired) {
	// Бинарный поиск

	// Инициализация переменных
	int low = 0;                 // Нижняя граница поиска
	int high = nums.length - 1;  // Верхняя граница поиска
	int mid;                     // Серединый индекс

	// Цикл поиск
	while (low <= high) {
		// Обновляем серединый индекс
		mid = (low + high) / 2;

		// Проверка, не найден ли искомый элемент
		if (nums.nums[mid] == desired) return mid;
		else if (nums.nums[mid] > desired) high = mid - 1;
		else low = mid + 1;
	}
	// Возвращаем -1, если элемент не найден
	return -1;
}

void naive_search(NUMS nums) {
	// Вкладка "Наивный поиск"

	// Очищаем консоль
	system("cls");

	int desired; // Число, которое нужно найти

	// Просим ввести число для поиска
	printf(" Введите число, которое хотите найти в массиве: ");
	scanf_s("%d", &desired);

	// Применяем алгорит наивного поиска
	int result = naive(nums, desired);

	// Вывод результата поиска
	(result > -1) ? printf("\n Чило найдено! Его индекс: %d", result) : printf("\n Числа %d нет в массиве!", desired);
	
	// Не обновлять консоль, пока не нажата клавиша
	printf("\n ");
	system("pause");
}

void binary_search(NUMS nums) {
	// Вкладка "Бинарный поиск"

	// Очищаем консоль
	system("cls");

	int desired; // Число, которое нужно найти

	// Проверяем, отсортирован ли массив
	if (check_is_sorted(nums)) {
		// Если отсортирован, запрашиваем ввод искомого числа
		printf(" Введите число, которое хотите найти в массиве: ");
		scanf_s("%d", &desired);

		// Сохраняем результат поиска
		int result = binary(nums, desired);

		// Выводим результат поиска
		(result > -1) ? printf("\n Чило найдено! Его индекс: %d", result) : printf("\n Числа %d нет в массиве!", desired);
	}
	// Если не отсортирован, просим исправить это
	else printf(" Массив не отсортирован! Пожалуйста, исправьте это и попробуйте вновь!");
	
	// Не обновляем консоль, пока не будет нажата клавиша
	printf("\n ");
	system("pause");
}