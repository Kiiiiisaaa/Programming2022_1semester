// ���������
#pragma once // ��������� �������������, ����������� ��������� Header.h ������ ������ ����

// ������������ ���������
#include <Windows.h>

// ���������
#define SORTINGS_NUM 4


typedef struct { // ��������� ��� �������� ����� ������� ����� � ��������� �� ����
	int length;
	int* nums;
} NUMS;


typedef struct { 
	// ��������� �� ��������������� �������: ����� ����������, 
	// ���������� ������������ � ���������� ���������
	int time;
	long long swaps;
	long long comparisons;
} STATS;


// ��������� ������� ����������
STATS bubble_sort(NUMS nums);
STATS shaker_sort(NUMS nums);
STATS selection_sort(NUMS nums);
STATS shell_sort(NUMS nums);


// ��������� �������, �������������� ���� � �������
void submenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
//    ����� ������������
void sorts_comparison(NUMS nums, char dir[100], char* sortings_names, STATS(*sortings[SORTINGS_NUM])(NUMS));
void efficiency(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS));
//    ���������
void naive_search(NUMS nums);
void binary_search(NUMS nums);
void sort_menu_by_ptr(NUMS nums, STATS(func)(NUMS), char path[100], char* name);
//    ���������
void show_current_array(NUMS nums, char dir[100]);
void set_path(char path[100]);
void get_nums_from_file_menu(NUMS* nums, char dir[100]);
void rand_gen_menu(NUMS* nums);
void users_array(NUMS* nums);


// ��������� �������, ���������� � �������
void get_nums_from_file(NUMS* result, char dir[100]);
void write_out_in_file(NUMS nums, char dir[100], char filename[100]);
