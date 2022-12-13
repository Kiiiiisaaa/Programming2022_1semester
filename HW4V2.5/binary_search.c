#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

int binary_search(int* values, int target, int length) { // ������� ��������� ������
    int start = 0, end = length - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
        if (values[mid] == target) return mid;
        else if (values[mid] > target) end = mid - 1;
        else start = mid + 1;
        mid = (start + end) / 2;
    }
    return -1;
}

void binary_search_menu(int* nums, int length) { // ���� ��������� ������
    system("cls");
    printf("  === �������� ����� ===\n");
    if (is_sorted(nums, length)) {
        printf("  ������� ������� �����: ");
        int n = read_num();
        int result = binary_search(nums, n, length);
        result == -1 ? printf("  ����� %d �� �������\n  ", n) : printf("  ����� %d �������! ��� ������: %d\n  ", n, result);
        system("pause");
    }
    else {
        printf("  ������� ������ �� ������������!\n  ");
        system("pause");
    }
}