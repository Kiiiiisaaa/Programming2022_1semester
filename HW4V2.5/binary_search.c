#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

int binary_search(int* values, int target, int length) { // функция бинарного поиска
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

void binary_search_menu(int* nums, int length) { // меню бинарного поиска
    system("cls");
    printf("  === Бинарный поиск ===\n");
    if (is_sorted(nums, length)) {
        printf("  Введите искомое число: ");
        int n = read_num();
        int result = binary_search(nums, n, length);
        result == -1 ? printf("  Число %d не найдено\n  ", n) : printf("  Число %d найдено! Его индекс: %d\n  ", n, result);
        system("pause");
    }
    else {
        printf("  Текущий массив не отсортирован!\n  ");
        system("pause");
    }
}