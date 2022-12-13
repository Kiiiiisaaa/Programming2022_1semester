// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// подключаем заголовочный файл чтобы использовать функции из дургих файлов
#include "Header.h"

// количества пунктов в каждом меню
#define MAIN_MENU_SIZE 5
#define ALG_MENU_SIZE 3
#define SEARCH_MENU_SIZE 3
#define SORT_MENU_SIZE 4
#define SETTINGS_MENU_SIZE 4



// объ¤вление главной функции
int main() {
    // настройки

    // задаЄм название консольного окна
    system("title Application");

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    // получаем дескриптор окна для обращени¤ к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // задаЄм серый фон дл¤ окна консоли
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // очищаем экран, чтобы настройка цвета применилась
    system("cls");

    // объ¤вление переменных
    int choose_pos;                    // переменна¤ дл¤ хранени¤ выбранного пункта меню
    int iKey;                          // переменна¤ дл¤ фиксации нажатой клавиши
    int exit_flag;                     // флаг на завершение программы
    COORD cursorPos;                   // управление положением курсора, чтобы мен¤ть выводимый текст
    // массивы пунктов соответсвующих меню
    char* main_menu[MAIN_MENU_SIZE] =         { (char*)"Сравнение сортировок",  (char*)"Эффективность сортировки",  (char*)"Алгоритмы",                 (char*)"Настройки", (char*)"Выход"};
    char* alg_menu[ALG_MENU_SIZE] =           { (char*)"Поиск",                 (char*)"Сортировки",                (char*)"Назад" };
    char* search_menu[SEARCH_MENU_SIZE] =     { (char*)"Наивный поиск",         (char*)"Бинарный поиск",            (char*)"Назад" };
    char* sort_menu[SORT_MENU_SIZE] =         { (char*)"Сортировка пузырек",    (char*)"Сортировка Хоара",          (char*)"Сортировка слиянием",       (char*)"Назад"};
    char* settings_menu[SETTINGS_MENU_SIZE] = { (char*)"Задать массив вручную", (char*)"Создать случайный массив",  (char*)"Посмотреть текущий массив", (char*)"Назад"};
 
    srand(time(NULL));
    int nums_length = 20000; // случайная длина массива чисел
    int* nums = gen(nums_length); // заполняем массив случайными числами

    // инициализаци¤ (заполнение значени¤ми) переменных
    exit_flag = 0;
    choose_pos = -1;


    while (!exit_flag) {      
        submenu(hStdOut, main_menu, MAIN_MENU_SIZE, &choose_pos); // отрисовываем главное меню

        // флаги для навигации по вкладкам меню
        int back_main_flag = 0;
        int back_alg_flag = 0;

        // главное меню
        switch (choose_pos) {
            case 0: {
                exp_menu(nums, nums_length);
                break;
            }
            case 1: {
                eff_menu();
                break;
            }
            case 2:
                // меню алгоритмов
                while (!back_main_flag) {
                    submenu(hStdOut, alg_menu, ALG_MENU_SIZE, &choose_pos);
                    back_main_flag = 0;
                    back_alg_flag = 0;
                    switch (choose_pos) {
                        case 2: {
                            // назад
                            back_main_flag = 1;
                            break;
                        }
                        case 0: {
                            // меню поисков
                            while (!back_alg_flag) {
                                submenu(hStdOut, search_menu, SEARCH_MENU_SIZE, &choose_pos);
                                switch (choose_pos) {
                                    case 0: {
                                        // наивный поиск
                                        naive_search(nums, nums_length);
                                        break;
                                    }
                                    case 1: {
                                        // бинарный поиск
                                        binary_search_menu(nums, nums_length);
                                        break;
                                    }
                                    case 2: {
                                        // назад
                                        back_alg_flag = 1;
                                        break;
                                    }
                                }
                            }
                        }
                        case 1: {
                            // меню сортировок
                            while (!back_alg_flag) {
                                submenu(hStdOut, sort_menu, SORT_MENU_SIZE, &choose_pos);
                                switch (choose_pos) {
                                    case 3: {
                                        // назад
                                        back_alg_flag = 1;
                                        break;
                                    }
                                    case 0: {
                                        // сортировка пузырьком
                                        int counter = 0;
                                        bubble_sort_menu(nums, nums_length, &counter);
                                        break;
                                    }
                                    case 1: {
                                        // сортировка Хоара
                                        int counter = 0;
                                        hoara_sorting_menu(nums, nums_length, &counter);
                                        break;
                                    }
                                    case 2: {
                                        // сортировка слиянием
                                        int counter = 0;
                                        merge_sorting_menu(nums, nums_length, &counter);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case 3:
                // меню настроек
                while (!back_alg_flag) {
                    submenu(hStdOut, settings_menu, SETTINGS_MENU_SIZE, &choose_pos);
                    switch (choose_pos) {
                        case 3: {
                            // назад
                            back_alg_flag = 1;
                            break;
                        }
                        case 0: {
                            // ввод массива
                            nums = set_array(nums, &nums_length);
                            break;
                        }
                        case 1: {
                            //заполнить массив случайными числами
                            nums_length = rand() % 11 + 5;
                            nums = gen(nums_length);
                            show_array(nums, nums_length);
                            break;
                        }
                        case 2: {
                            // вывод текущего массива
                            show_array(nums, nums_length);
                            break;

                        }
                    }
                }
                break;
            case 4:
                exit_flag = 1;
                break;
            }
    }
    // вывод результата
    system("cls");
    printf("  Пока-пока)!\n  ");

    // завершение программы
    system("pause");
    return 0;
}