#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


void hoara(int* nums, int length, int* counter) { hoara_sorting(nums, 0, length - 1, counter); }

void hoara_sorting(int* nums, int start, int end, int* counter)
{
    int i = start, j = end;
    double tmp, x = nums[(start + end) / 2];
    do {
        while (nums[i] < x) i++;
        while (nums[j] > x) j--;
        if (i <= j) {
            if (i < j) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                *counter = *counter + 1;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < end)
        hoara_sorting(nums, i, end, counter);
    if (start < j)
        hoara_sorting(nums, start, j, counter);
}

void hoara_sorting_menu(int* nums, int length, int* counter) {
    system("cls");
    printf("  === Сортировка Хоара ===\n");
    printf("  Исходный массив: ");
    (length <= 15) ? print_array(nums, length) : printf("%d элементов", length);
    hoara(nums, length, counter);
    if (length <= 15) { printf("\n  Отсортированный массив: "); print_array(nums, length); }
    printf("\n  Произведено перестановок: %d", *counter);
    printf("\n  ");
    system("pause");
}