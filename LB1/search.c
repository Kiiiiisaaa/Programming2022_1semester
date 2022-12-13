// ������������ ����������
#include <stdlib.h>
#include <stdio.h>

// ������������ ����
#include "Header.h"

int check_is_sorted(NUMS nums) {
	// ��������, ������������ �� ������
	for (int i = 1; i < nums.length; i++) if (nums.nums[i - 1] > nums.nums[i]) return 0;
	return 1;
}

int naive(NUMS nums, int desired) {
	// ������� �����
	for (int i = 0; i < nums.length; i++) if (nums.nums[i] == desired) return i;
	return -1;
}

int binary(NUMS nums, int desired) {
	// �������� �����

	// ������������� ����������
	int low = 0;                 // ������ ������� ������
	int high = nums.length - 1;  // ������� ������� ������
	int mid;                     // ��������� ������

	// ���� �����
	while (low <= high) {
		// ��������� ��������� ������
		mid = (low + high) / 2;

		// ��������, �� ������ �� ������� �������
		if (nums.nums[mid] == desired) return mid;
		else if (nums.nums[mid] > desired) high = mid - 1;
		else low = mid + 1;
	}
	// ���������� -1, ���� ������� �� ������
	return -1;
}

void naive_search(NUMS nums) {
	// ������� "������� �����"

	// ������� �������
	system("cls");

	int desired; // �����, ������� ����� �����

	// ������ ������ ����� ��� ������
	printf(" ������� �����, ������� ������ ����� � �������: ");
	scanf_s("%d", &desired);

	// ��������� ������� �������� ������
	int result = naive(nums, desired);

	// ����� ���������� ������
	(result > -1) ? printf("\n ���� �������! ��� ������: %d", result) : printf("\n ����� %d ��� � �������!", desired);
	
	// �� ��������� �������, ���� �� ������ �������
	printf("\n ");
	system("pause");
}

void binary_search(NUMS nums) {
	// ������� "�������� �����"

	// ������� �������
	system("cls");

	int desired; // �����, ������� ����� �����

	// ���������, ������������ �� ������
	if (check_is_sorted(nums)) {
		// ���� ������������, ����������� ���� �������� �����
		printf(" ������� �����, ������� ������ ����� � �������: ");
		scanf_s("%d", &desired);

		// ��������� ��������� ������
		int result = binary(nums, desired);

		// ������� ��������� ������
		(result > -1) ? printf("\n ���� �������! ��� ������: %d", result) : printf("\n ����� %d ��� � �������!", desired);
	}
	// ���� �� ������������, ������ ��������� ���
	else printf(" ������ �� ������������! ����������, ��������� ��� � ���������� �����!");
	
	// �� ��������� �������, ���� �� ����� ������ �������
	printf("\n ");
	system("pause");
}