#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int count_max(int* arr, int n) {
	int count = 0;
	for (int i = 1; i < n - 1; i++) if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) count++;
	return count;
}

int* maxes(int* arr, int n, int count) {
	int* res = (int*)malloc(count * sizeof(int));
	int pos = 0;
	for (int i = 1; i < n - 1; i++) if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) { res[pos] = arr[i]; pos++; }
	return res;

}

int min_from_maxes(int* res, int count) {
	int min = 2147483647;
	for (int i = 0; i < count; i++) if (min > res[i]) min = res[i];
	return min;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	int n;
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	printf("Введите массив: ");
	for (int i = 0; i < n; i++) scanf_s("%d", &arr[i]);
	int count = count_max(arr, n);
	int* res = maxes(arr, n, count);
	int min = min_from_maxes(res, count);


	printf("Результат: минимальный из %d локальных максимумов [", count);
	for (int i = 0; i < count; i++) printf(" %d ", res[i]);
	printf("] равен %d", min);
	return 0;
}