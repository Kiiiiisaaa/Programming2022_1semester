#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

void bubble(int* nums, int length, long* counter) { bubble_sort(nums, length, counter); }

void bubble_sort(int* nums, int length, long* counter) {
    int sorted = 0;
    int temp;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                sorted = 0;
                *counter = *counter + 1;
            }
        }
    }
}


void bubble_sort_menu(int* nums, int length, int* counter) { // ���������� ���������
    system("cls");
    printf("  === ����������� ���������� ===\n");
    printf("  �������� ������: ");
    (length <= 15) ? print_array(nums, length): printf("%d ���������", length);
    bubble(nums, length, counter);
    if (length <= 15) { printf("\n  ��������������� ������: "); print_array(nums, length); }
    printf("\n  ����������� ������������: %d", *counter);
    printf("\n  ");
    system("pause");
}