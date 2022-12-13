#include <stdlib.h >
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "Header.h"




void eff_menu() {
	system("cls");
	printf("  === Оценка эффективности ===\n");/*
	printf("  Алгоритмы: 1. Сортировка пузырьком\n\t     2. Сортировка Хоара\n\t     3. Сортировка слиянием");
	int n = -1;
	int len;
	do { printf("\n Выберите алгоритм: "); scanf_s("%d", &n); } while (n < 1 || n > 3);*/
	int len;
	int counter;
	int* temp;
	clock_t t = clock(NULL);
	int (*funcs[3])(int*, int, int*) = { bubble, hoara, merge };
	char* names[3] = { (char*)"Сортировка пузырьком", (char*)"Сортировка Хоара", (char*)"Сортировка слиянием" };
	printf("  Название сортировки\t\tЭлементов\tТактов\t\tКол-во перестановок\n");
	for (int i = 0; i < 3; i++) {
		printf("\n");
		for (int j = 1; j < 4; j++) {
			len = pow(10, j + 1);
			temp = gen(len);
			counter = 0;
			t = clock(NULL);
			funcs[i](temp, len, &counter);
			t = clock(NULL) - t;
			printf("  %s\t\t%d\t\t%d\t\t%d\n", names[i], len, t, counter);
		}
	}
	printf("\n\n\n");
	system("pause");
}