#include <stdlib.h >
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "Header.h"




void eff_menu() {
	system("cls");
	printf("  === ������ ������������� ===\n");/*
	printf("  ���������: 1. ���������� ���������\n\t     2. ���������� �����\n\t     3. ���������� ��������");
	int n = -1;
	int len;
	do { printf("\n �������� ��������: "); scanf_s("%d", &n); } while (n < 1 || n > 3);*/
	int len;
	int counter;
	int* temp;
	clock_t t = clock(NULL);
	int (*funcs[3])(int*, int, int*) = { bubble, hoara, merge };
	char* names[3] = { (char*)"���������� ���������", (char*)"���������� �����", (char*)"���������� ��������" };
	printf("  �������� ����������\t\t���������\t������\t\t���-�� ������������\n");
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