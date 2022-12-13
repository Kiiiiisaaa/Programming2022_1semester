#include <stdlib.h >
#include <stdio.h>
#include <time.h>

#include "Header.h"

int* rewrite(int* nums, int length) {
	int* temp = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) temp[i] = nums[i];
	return temp;
}

void exp_menu(int* nums, int length) {
	system("cls");
	printf("  === ����������� ===\n");
	printf("  ��������� � ������� �������: %d", length);
	int* temp = rewrite(nums, length);
	long counter = 0;
	clock_t t;
	int (*funcs[3])(int*, int, int*) = { bubble, hoara, merge };
	char* names[3] = { (char*)"���������� ���������", (char*)"���������� �����", (char*)"���������� ��������" };
	printf("\n  �������� ����������\t\t����� (�����)\t\t���-�� ������������");
	for (int i = 0; i < 3; i++) {
		counter = 0;
		temp = rewrite(nums, length);
		t = clock(NULL);
		funcs[i](temp, length, &counter);
		t = clock(NULL) - t;
		printf("\n  %s\t\t%d\t\t\t%d", names[i], t, counter);
	}
	printf("\n\n\n");
	system("pause");
}