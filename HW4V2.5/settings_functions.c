#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


int* gen(int length) {
    srand(time(NULL));
    int* nums = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) nums[i] = rand() % 100;
    return nums;
}


int is_sorted(int* nums, int length) {// проверка массива на отсортированность
    int sorted = 1;
    for (int i = 0; i < length - 1; i++) if (nums[i] > nums[i + 1]) { sorted = 0; break; }
    return sorted;
}

int read_num() { // считывание числа из потока ввода
    int n = 0;
    char* c;
    fseek(stdin, 0, SEEK_END);
    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            n = n * 10 + (int)c - '0';
        }
    }
    return n;
}

void print_array(int* nums, long length) { // вывод массива
    printf("{");
    for (int i = 0; i < length; i++) printf(" %d ", nums[i]);
    printf("}");
}

int* set_array(int* nums, long* nums_length) { // ввод нового текущего массива
    system("cls");
    printf("  === Изменение массива ===\n");
    printf("  Введите количество элементов: ");
    int n = read_num();
    system("cls");
    printf("  === Изменение массива ===\n");
    printf("  Введите количество элементов: %d\n", n);
    printf("  Введите через пробел элементы массива: ");
    nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf_s("%d", &nums[i]);
    printf("  ");
    system("pause");
    *nums_length = n;
    return nums;
}

void show_array(int* nums, long length) { // меню вывода массива
    system("cls");
    printf("  === Просмотр текущего массива === \n ");
    print_array(nums, length);
    printf("\n");
    system("pause");
}
