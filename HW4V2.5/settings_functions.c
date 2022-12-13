#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


int* gen(int length) {
    srand(time(NULL));
    int* nums = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) nums[i] = rand() % 100;
    return nums;
}


int is_sorted(int* nums, int length) {// �������� ������� �� �����������������
    int sorted = 1;
    for (int i = 0; i < length - 1; i++) if (nums[i] > nums[i + 1]) { sorted = 0; break; }
    return sorted;
}

int read_num() { // ���������� ����� �� ������ �����
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

void print_array(int* nums, long length) { // ����� �������
    printf("{");
    for (int i = 0; i < length; i++) printf(" %d ", nums[i]);
    printf("}");
}

int* set_array(int* nums, long* nums_length) { // ���� ������ �������� �������
    system("cls");
    printf("  === ��������� ������� ===\n");
    printf("  ������� ���������� ���������: ");
    int n = read_num();
    system("cls");
    printf("  === ��������� ������� ===\n");
    printf("  ������� ���������� ���������: %d\n", n);
    printf("  ������� ����� ������ �������� �������: ");
    nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf_s("%d", &nums[i]);
    printf("  ");
    system("pause");
    *nums_length = n;
    return nums;
}

void show_array(int* nums, long length) { // ���� ������ �������
    system("cls");
    printf("  === �������� �������� ������� === \n ");
    print_array(nums, length);
    printf("\n");
    system("pause");
}
