// ������������ ����������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/stat.h"

// ������������ ����
#include "Header.h"


void get_nums_from_file(NUMS* result, char dir[100]) {
	// �������� ����� �� ����� input.txt ���������� dir � ��������� nums

	// �������� ����� ����� ��� ������
	char filename[100] = "input.txt";
	char filepath[200];
	strcpy_s(filepath, sizeof filepath, dir);
	strncat_s(filepath, 100, filename, 100);

	(*result).length = -1;
	
	// ���������� ���������� 
	FILE* input_file = NULL;  // ��� �����
	errno_t error;            // ��� ��������� ������
	int size;                 // ���������� ����� � �����
	int* mass = NULL;         // ��������� ������ ��� ���������� ���������� �����

	// ��������� ����
	error = fopen_s(&input_file, filepath, "r+"); // r � read, w - write

	// ��������, ���������� �� ����
	if (input_file == NULL) {
		printf("\n  ���� �� ����������! �������� ��� � ��������� ��������� �����!\n  ");
		return;
	}
	else {
		// ���� ���� ���������

		// ���������, �� ���� �� ����
		if (fscanf_s(input_file, "%d", &size) != 1) {
			printf("\n  ���� � ���������� ������� ����! ��������� ��� � ��������� ��������� �����!\n  ");
			return;
		}
		// ���� �� ����
		// �������������� ������ ��� �����
		mass = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++) {
			// ��������� �����
			if (fscanf_s(input_file, "%d", &mass[i]) != 1) {
				return;
			}
		}

		// ��������� ����
		fclose(input_file);
	}

	// �������������� ���������, ����� ������� ��
	(*result).length = size;
	(*result).nums = mass;
	return;
}

void write_out_in_file(NUMS nums, char dir[100], char filename[100]) {
	// ���������� ����� nums � ���� filename ���������� dir

	// �������� ������ ����� ��� ������
	char filepath[200];
	strcpy_s(filepath, sizeof filepath, dir);
	strncat_s(filepath, 100, filename, 100);

	// ������������� ����������
	FILE* output_file = NULL;  // ��� �����
	errno_t error;             // ��� ��������� ������

	// ��������� ����
	error = fopen_s(&output_file, filepath, "w+"); // r � read, w - write

	// ��������, ���������� �� ����
	if (output_file == NULL) {
		printf("\n\n ������! ���� %s �� ������!", filename);
		return;
	}
	else {
		// ���� ����������, ���������� ����� � ���� ����
		fprintf_s(output_file, "%d ", nums.length);
		for (int i = 0; i < nums.length; i++) {
			fprintf_s(output_file, "%d ", nums.nums[i]);
		}

		// ��������� ����
		fclose(output_file);
	}
	return;
}
