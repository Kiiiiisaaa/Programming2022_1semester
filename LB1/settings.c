// ������������ ����������
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ������������ ����
#include "Header.h"



void show_current_array(NUMS nums, char dir[100]) {
	// ������� ������ �������� �������

	// ������� �������
	system("cls");
	if (nums.length <= 20) {

		// ���� � ������� <= 20 ��������� - ������� � �������
		printf(" ������� ������: \n");
		for (int i = 0; i < nums.length; i++) printf(" %d ", nums.nums[i]);
	}
	else {
		// ����� - ������� � output.txt ������� ������� ���������� 
		printf(" ������� ������ �������� ����� 20 ���������. ������ ��� �������� � ���� output.txt ������� ����������");
		write_out_in_file(nums, dir, "output.txt\0");
	}

	// �� ��������� �������, ���� �� ������ �������
	printf("\n ");
	system("pause");
}

void set_path(char path[100]) {
	// ��������� ������� ����������

	// ������� �������
	system("cls");

	// ����� ������� ���������� � ����������� ������ �����
	printf(" ������� ����������: %s\n", path);
	printf(" ������� ����� ����������: ");

	// ������������� ����������
	int i = 0; // ������ ��� �����
	char c;    // ���������� ���������� ��� ���������� ���������� �������

	// ��������������� ����
	while ((c = getchar()) != '\n') {
		path[i++] = c;
	}

	// ��������� ������� ����� ������
	path[i] = '\0';

	// �� ��������� �������, ���� �� ������ �������
	printf("\n �������!\n ");
	system("pause");
}

void get_nums_from_file_menu(NUMS* nums, char dir[100]) {
	// ������� "��������� �� �����"

	// ������� �����
	system("cls");

	// �������� ����� �� �����
	get_nums_from_file(nums, dir);

	// �� ��������� �������, ���� �� ������ �������
	printf(" ������ ������� �������! ����� � �������: %d\n ", (*nums).length);
	system("pause");
}

void rand_gen_menu(NUMS* nums) {
	// ������� "������������� ��������"

	// ������������� ���������
	int is_correct = 0, length = -1, low = 0, high = 100;
	// ������ ���������� ��������� �������
	while (!is_correct) {
		system("cls");
		printf(" ������� ���������� ��������� � �������: ");
		scanf_s("%d", &length);
		if (length > 0) is_correct = 1;
	}
	// ���� ������������ ����������� ��������
	printf("\n ������� �����������  ���������� �������� � �������: ");
	scanf_s("%d", &low);

	// ���� ������������ ����������� ��������
	printf("\n ������� ������������ ���������� �������� � �������: ");
	scanf_s("%d", &high);

	// ������ ��������������� ����� ��������� �� ���, ��� ���� � ���������� ������� ����������
	srand(time(NULL));

	// ������� ��������� �� ������ ��� �����
	int* tmp = (int*)malloc(sizeof(int) * length);

	// ��������� ���������� ������� �� ��������� ������������� ���������
	for (int i = 0; i < length; i++) tmp[i] = rand() % (high - low + 1) + low;

	// ��������� ��������������� ������ � nums
	(*nums).nums = tmp;
	(*nums).length = length;

	// �� ��������� �������, ���� �� ������ �������
	printf("\n ������ ������� ������������!\n ");
	system("pause");
}

void users_array(NUMS* nums) {
	// ������� "������ �������"
	
	// ��������� ����� �������
	int length = 0;
	while (length < 1) {
		system("cls");
		printf(" ������� ���������� ���������: ");
		scanf_s("%d", &length);
	}

	// ������� ��������� �� ������
	int* tmp = (int*)malloc(sizeof(int) * length);

	// ����������� ���� �����
	printf(" ������� �������� �������: ");
	for (int i = 0; i < length; i++) scanf_s("%d", &tmp[i]);

	// ��������� ��������� � nums
	(*nums).length = length;
	(*nums).nums = tmp;

	// �� ��������� �������, ���� �� ������ �������
	printf("\n �������!\n ");
	system("pause");
}