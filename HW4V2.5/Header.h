#pragma once
#include <windows.h>
#include <conio.h>


void submenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
void merge_sorting(int* nums, int* scratch, int start, int end, int* counter);
void hoara_sorting(int* nums, int start, int end, int* counter);
void binary_search_menu(int* nums, int length);
void naive_search(int* nums, int length);
void bubble_sort(int* nums, int length, int* counter);
void bubble_sort_menu(int* nums, int length, int* counter);
void hoara_sorting_menu(int* nums, int length, int* counter);
void merge_sorting_menu(int* nums, int length, int* counter);
void exp_menu(int* nums, int length);
void eff_menu();

void bubble(int* nums, int length, long* counter);
void merge(int* nums, int length, int* counter);
void hoara(int* nums, int length, int* counter);
int is_sorted(int* nums, int length);
int read_num(); 
int* gen(int length); 
int* set_array(int* nums, int* nums_length);
void show_array(int* nums, int length);
void print_array(int* nums, int length);
int* rewrite(int* nums, int length);
