// ������������ ����������
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // ��� ���������� � �������

// ������������ ����
#include "Header.h"

double get_min(int arr[SORTINGS_NUM]) {
	// ��������� ������������ �������� �� �������, ��� SORTINGS_NUM ���������
	double min = arr[0];
	for (int i = 0; i < SORTINGS_NUM; i++) if (min > arr[i]) min = arr[i];
	if (min == 0) min = 0.00001;
	return min;
}
double get_min_by_ptr(int* arr, int length) {
	// ��������� ������������ �������� �� ������� �� ������� arr � ������� length
	int min = arr[0];
	for (int i = 0; i < length; i++) if (min > arr[i]) min = arr[i];
	if (min == 0) return 0.00001;
	return (double)min;
}

void sorts_comparison(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS)) {
	// ��������� ����������

	// ������� �������
	system("cls"); 

	// ���������� ������� ������ � ���� input.txt
	write_out_in_file(nums, dir, "input.txt\0");

	printf("========================================== C�������� ���������� ============================================");
	
	// ���������� ����������
	int times[SORTINGS_NUM];       // ����� ������ ����������
	int swaps[SORTINGS_NUM];       // ������������ � ���������� ������ ����������
	int comparisons[SORTINGS_NUM]; // ��������� � ���������� ������ ����������

	for (int i = 0; i < SORTINGS_NUM; i++) {
		// ���� ����������

		// �������� ����������������� ������, ������� 
		// �� �������� �������, �� ����� input.txt
		get_nums_from_file(&nums, dir);

		// �������� ������
		STATS current_func_stats = sortings[i](nums);

		// ��������� ������ � �������������� �������
		times[i] = current_func_stats.time;
		swaps[i] = current_func_stats.swaps;
		comparisons[i] = current_func_stats.comparisons;
	}

	// ���������� ����������
	double delta_times[SORTINGS_NUM];       // ����������
	double delta_swaps[SORTINGS_NUM];       // ���������� ����� ������������
	double delta_comparisons[SORTINGS_NUM]; // ���������� ����� ���������

	for (int i = 0; i < SORTINGS_NUM; i++) {
		// ������� ���������� � ���������� ����� ������������ � ���������
		delta_times[i] = times[i] / get_min(times);
		delta_swaps[i] = swaps[i] / get_min(swaps);
		delta_comparisons[i] = comparisons[i] / get_min(comparisons);
	}

	// ����� ������� � ������������
	printf("\n\n \t\t\t\t\t\t\t\t���������\t\t\t���������");
	printf("\n \t\t\t\t\t\t����������\t�����\t\t����������\t�����");
	printf("\n ����������\t\t�����\t����������\t������������\t������������\t���������\t���������");
	printf("\n============================================================================================================");
	for (int i = 0; i < SORTINGS_NUM; i++) printf("\n %16s %8d %11.2lf %17d %15.2lf %14d %13.2lf", sortings_names[i],  times[i], delta_times[i], swaps[i], delta_swaps[i], comparisons[i], delta_comparisons[i]);
	
	// �� ��������� ������� ���� �� ������ �������
	printf("\n\n ");
	system("pause");
}

void rand_gen(NUMS* nums, int length) {
	// ���������� ��������� ������ �������� �����
	int* temp = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) temp[i] = rand() % 999 + 1;
	(*nums).nums = temp;
	(*nums).length = length;
}

void efficiency(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS)) {
	// ������� "�������������"
	
	// ������� �������
	system("cls");

	// ������� ������ ��������� ����������
	printf(" ��������� ����������: ");
	for (int i = 0; i < SORTINGS_NUM; i++) printf("\n %d. %s", i + 1, sortings_names[i]);

	// ���������� ������� ����������
	int choose = 0;
	while (choose < 1 || choose > SORTINGS_NUM) {
		printf("\n\n �������� ����������: ");
		scanf_s("%d", &choose);
	}
	choose--;

	// ���������� ������ ���������� �������
	int tests_num = 0;
	while (!(tests_num >= 1)) {
		printf("\n ������� ���������� �������: ");
		scanf_s("%d", &tests_num);
	}

	// ���������� ������ ������� ��������������� ��������, ��������� � lengths
	printf(" ������� ���������� ��������� � %d ��������: ", tests_num);
	int* lengths = (int*)malloc(sizeof(int) * tests_num);
	for (int i = 0; i < tests_num; i++) scanf_s("%d", &lengths[i]);

	// ������������� �������� �� ��������� ������ � ���������������� ������������
	int* times = (int*)malloc(sizeof(int) * tests_num);
	double* delta_times = (double*)malloc(sizeof(double) * tests_num);

	// ���������� ������ ������
	for (int i = 0; i < tests_num; i++) {
		rand_gen(&nums, lengths[i]);
		STATS result = sortings[choose](nums);
		if (times != NULL) times[i] = (int)result.time;
	}

	// ������ ����������
	for (int i = 0; i < tests_num; i++) delta_times[i] = times[i] / get_min_by_ptr(times, tests_num);

	// ����� ������� �����������
	printf("\n\n");
	printf(" ������ �������\t  ����� ������\t����������");
	for (int i = 0; i < tests_num; i++) printf("\n %14d %14d %11.3lf", lengths[i], times[i], delta_times[i]);
	printf("\n\n ");
	system("pause");
}