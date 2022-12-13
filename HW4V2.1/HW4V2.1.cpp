#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_CTYPE, "rus");
	int n;
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	printf("Введите массив: ");
	for (int i = 0; i < n; i++) scanf_s("%d", &arr[i]);
	int count = 0;
	for (int i = 1; i < n - 1; i++) if (arr[i - 1] > arr[i] && arr[i + 1] > arr[i]) count++;
	printf("Количество локальных минимумов: %d", count);
	return 0;
}