#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

void naive_search(int* nums, int length) { // ������� �����
    system("cls");
    printf("  === ������� ����� ===\n");
    printf("  ������� ������� �����: ");
    int n = read_num();
    int result = -1;
    for (int i = 0; i < length; i++) {
        if (nums[i] == n) {
            result = i;
            break;
        }
    }
    result == -1 ? printf("  ����� %d �� �������\n  ", n) : printf("  ����� %d �������! ��� ������: %d\n  ", n, result);
    system("pause");
}
