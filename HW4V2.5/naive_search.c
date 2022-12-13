#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

void naive_search(int* nums, int length) { // наивный поиск
    system("cls");
    printf("  === Наивный поиск ===\n");
    printf("  Введите искомое число: ");
    int n = read_num();
    int result = -1;
    for (int i = 0; i < length; i++) {
        if (nums[i] == n) {
            result = i;
            break;
        }
    }
    result == -1 ? printf("  Число %d не найдено\n  ", n) : printf("  Число %d найдено! Его индекс: %d\n  ", n, result);
    system("pause");
}
