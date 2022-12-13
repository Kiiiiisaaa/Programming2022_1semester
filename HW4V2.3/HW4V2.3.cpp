#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

int* array_gen(int n) {
	srand(time(NULL));
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) arr[i] = rand();
	return arr;
}

void print_arr(int* arr, int n) {
	printf("[");
	for (int i = 0; i < n; i++) printf(" %d ", arr[i]);
	printf("]");
}


int* sort(int* arr, int n) {
	int max, max_i, temp;
	int comparisons = 0;
	int swaps = 0;
	while (n != 0) {
		max = -1;
		max_i = -1;
		for (int i = 0; i < n; i++) if (max < arr[i]) { max = arr[i]; max_i = i; comparisons += 2; }
		temp = arr[max_i];
		arr[max_i] = arr[n-1];
		arr[n-1] = temp;
		swaps++;
		n--;
	}
	int* res = (int*)malloc(2 * sizeof(int));
	res[0] = swaps;
	res[1] = comparisons;
	return res;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	int n;
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	int* arr = array_gen(n);
	printf("Изначальный массив: "); print_arr(arr, n);
	int* data = sort(arr, n);
	printf("\nОтсортированный массив: "); print_arr(arr, n);
	printf("\nДля сортировки потребовалось %d перестановок и %d сравнений.", data[0], data[1]);
	return 0;
}