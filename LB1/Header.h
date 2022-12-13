// Директивы
#pragma once // Директива препроцессора, запрещающая запускать Header.h больше одного раза

// Используемые директивы
#include <Windows.h>

// Константы
#define SORTINGS_NUM 4


typedef struct { // Структура для хранения длины массива чисел и указателя на него
	int length;
	int* nums;
} NUMS;


typedef struct { 
	// Структура со статистическими даннымы: время выполнения, 
	// количество перестановок и количество сравнений
	int time;
	long long swaps;
	long long comparisons;
} STATS;


// Прототипы функций сортировки
STATS bubble_sort(NUMS nums);
STATS shaker_sort(NUMS nums);
STATS selection_sort(NUMS nums);
STATS shell_sort(NUMS nums);


// Прототипы функций, отрисовывающих меню и вкладки
void submenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
//    Режим эксперимента
void sorts_comparison(NUMS nums, char dir[100], char* sortings_names, STATS(*sortings[SORTINGS_NUM])(NUMS));
void efficiency(NUMS nums, char dir[100], char* sortings_names[SORTINGS_NUM], STATS(*sortings[SORTINGS_NUM])(NUMS));
//    Алгоритмы
void naive_search(NUMS nums);
void binary_search(NUMS nums);
void sort_menu_by_ptr(NUMS nums, STATS(func)(NUMS), char path[100], char* name);
//    Настройки
void show_current_array(NUMS nums, char dir[100]);
void set_path(char path[100]);
void get_nums_from_file_menu(NUMS* nums, char dir[100]);
void rand_gen_menu(NUMS* nums);
void users_array(NUMS* nums);


// Прототипы функций, работающих с файлами
void get_nums_from_file(NUMS* result, char dir[100]);
void write_out_in_file(NUMS nums, char dir[100], char filename[100]);
