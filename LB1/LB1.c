
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <math.h> 
#include <Windows.h> 

// Заголовочный файл для разбиения программы на несколько файлов
#include "Header.h"



#define CONSOLE_COLOR_STYLE 0x9F

#define MAIN_MENU_SIZE 4		
#define EXP_MENU_SIZE 3			
#define ALG_MENU_SIZE 3			
#define SEARCH_MENU_SIZE 3		
#define SORT_MENU_SIZE 5		 
#define SETTINGS_MENU_SIZE 4	
#define SET_ARR_MENU_SIZE 4		



int main() { 


	system("title Лабораторная Работа № 1"); 

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	
	SetConsoleTextAttribute(hStdOut, CONSOLE_COLOR_STYLE);

	system("cls");

	char* main_menu[MAIN_MENU_SIZE] = { 
		"Режим эксперимента",
		"Алгоритмы",
		"Настройки",
		"Выход"
	};
	char* exp_menu[EXP_MENU_SIZE] = { 
		"Сравнение сортировок",
		"Эффективность",
		"Назад"
	};
	char* alg_menu[ALG_MENU_SIZE] = { 
		"Поиск",
		"Сортировка",
		"Назад"
	};
	char* search_menu[SEARCH_MENU_SIZE] = { 
		"Наивный поиск",
		"Бинарный поиск",
		"Назад"
	};
	char* sort_menu[SORT_MENU_SIZE] = { 
		"Пузырьковая сортировка",
		"Сортировка Шелла (последовательность Седжвика)",
		"Шейкерная сортировка",
		"Сортировка выбором",
		"Назад"
	};
	char* settings_menu[SETTINGS_MENU_SIZE] = { 
		"Задать массив",
		"Показать текущий массив",
		"Изменить путь до рабочей директории",
		"Назад" };
	char* set_array_menu[SET_ARR_MENU_SIZE] = { 
		"Задать вручную",
		"Сгенерировать случайно",
		"Прочитать из файла",
		"Назад"
	};

	char* sortings_names[SORTINGS_NUM] = { 
		"Сортировка пузырьком",
		"Сортировка Шелла    ",
		"Шейкерная сортировка",
		"Сортировка выбором  ",
	};

	STATS(*sortings[SORTINGS_NUM])(NUMS) = { 
		bubble_sort,
		shell_sort,
		shaker_sort,
		selection_sort,
	};

	int choose_pos = -1;  
	int exit_flag = 0;   
	int back_main_fl = 0; 
	int back_exp_fl = 0;  
	int back_alg_fl = 0;  
	int back_set_fl = 0;  
	char path[100] = "C:\\Users\\Артем\\source\\repos\\HW\\LB1\\";
	NUMS nums; 

	
	get_nums_from_file(&nums, path);
	if (nums.length == -1) { 
		system("pause");
		return 1;
	}

	while (!exit_flag) {
		submenu(hStdOut, main_menu, MAIN_MENU_SIZE, &choose_pos);
		back_main_fl = 0; 

		switch (choose_pos) {
			case 0: {
				while (!back_main_fl) {
					submenu(hStdOut, exp_menu, EXP_MENU_SIZE, &choose_pos);

					switch (choose_pos) {
						case 0: {
							sorts_comparison(nums, path, sortings_names, sortings);
							break;
						}
						case 1: {
							efficiency(nums, path, sortings_names, sortings);
							break;
						}
						case 2: {
							back_main_fl = 1;
							break;
						}
					}
				}
				break;
			}
			case 1: {
				while (!back_main_fl) {
					submenu(hStdOut, alg_menu, ALG_MENU_SIZE, &choose_pos);
					back_alg_fl = 0;
					switch (choose_pos) {
						case 0: {
							while (!back_alg_fl) {
								submenu(hStdOut, search_menu, SEARCH_MENU_SIZE, &choose_pos);
								switch (choose_pos) {
									case 0: {
										naive_search(nums);
										break;
									}
									case 1: {
										binary_search(nums);
										break;
									}
									case 2: {
										back_alg_fl = 1;
										break;
									}
								}
							}
							break;
						}
						case 1: {
							while (!back_alg_fl) {
								submenu(hStdOut, sort_menu, SORT_MENU_SIZE, &choose_pos);

								switch (choose_pos) {
									case 0: case 1: case 2: case 3: {
										sort_menu_by_ptr(nums, sortings[choose_pos], path, sortings_names[choose_pos]);
										break;
									}
									case 4: {
										back_alg_fl = 1;
										break;
									}
								}
							}
							break;
						}
						case 2: {
							back_main_fl = 1;
							break;
						}
					}
				}
				break;
			}
			case 2: {
				while (!back_main_fl) {
					submenu(hStdOut, settings_menu, SETTINGS_MENU_SIZE, &choose_pos);
					back_set_fl = 0;

					switch (choose_pos) {
						case 0: {
							while (!back_set_fl) {
								submenu(hStdOut, set_array_menu, SET_ARR_MENU_SIZE, &choose_pos);

								switch (choose_pos) {
									case 0: {
										users_array(&nums);
										break;
									}
									case 1: {
										rand_gen_menu(&nums);
										break;
									}
									case 2: {
										get_nums_from_file_menu(&nums, path);
										break;
									}
									case 3: {
										back_set_fl = 1;
										break;
									}
								}
							}
							break;
						}
						case 1: {
							show_current_array(nums, path);
							break;
						}
						case 2: {
							set_path(path);
							break;
						}
						case 3: {
							back_main_fl = 1;
							break;
						}
					}
				}
				break;
			}
			case 3: {
				system("cls");
				printf(" Пока-пока!");
				exit_flag = 1;
				break;
			}
		}
	}
}