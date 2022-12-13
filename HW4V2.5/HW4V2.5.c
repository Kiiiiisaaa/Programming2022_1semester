// ����������
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// ���������� ������������ ���� ����� ������������ ������� �� ������ ������
#include "Header.h"

// ���������� ������� � ������ ����
#define MAIN_MENU_SIZE 5
#define ALG_MENU_SIZE 3
#define SEARCH_MENU_SIZE 3
#define SORT_MENU_SIZE 4
#define SETTINGS_MENU_SIZE 4



// ���������� ������� �������
int main() {
    // ���������

    // ����� �������� ����������� ����
    system("title Application");

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

    // �������� ���������� ���� ��� �������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���������� ������ ������� � ������� (� ����� ���� ������ ������)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // ����� ����� ��� �� ���� �������
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // ������� �����, ����� ��������� ����� �����������
    system("cls");

    // ���������� ����������
    int choose_pos;                    // ��������� �� ������� ���������� ������ ����
    int iKey;                          // ��������� �� �������� ������� �������
    int exit_flag;                     // ���� �� ���������� ���������
    COORD cursorPos;                   // ���������� ���������� �������, ����� ����� ��������� �����
    // ������� ������� �������������� ����
    char* main_menu[MAIN_MENU_SIZE] =         { (char*)"��������� ����������",  (char*)"������������� ����������",  (char*)"���������",                 (char*)"���������", (char*)"�����"};
    char* alg_menu[ALG_MENU_SIZE] =           { (char*)"�����",                 (char*)"����������",                (char*)"�����" };
    char* search_menu[SEARCH_MENU_SIZE] =     { (char*)"������� �����",         (char*)"�������� �����",            (char*)"�����" };
    char* sort_menu[SORT_MENU_SIZE] =         { (char*)"���������� �������",    (char*)"���������� �����",          (char*)"���������� ��������",       (char*)"�����"};
    char* settings_menu[SETTINGS_MENU_SIZE] = { (char*)"������ ������ �������", (char*)"������� ��������� ������",  (char*)"���������� ������� ������", (char*)"�����"};
 
    srand(time(NULL));
    int nums_length = 20000; // ��������� ����� ������� �����
    int* nums = gen(nums_length); // ��������� ������ ���������� �������

    // ������������ (���������� ���������) ����������
    exit_flag = 0;
    choose_pos = -1;


    while (!exit_flag) {      
        submenu(hStdOut, main_menu, MAIN_MENU_SIZE, &choose_pos); // ������������ ������� ����

        // ����� ��� ��������� �� �������� ����
        int back_main_flag = 0;
        int back_alg_flag = 0;

        // ������� ����
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
                // ���� ����������
                while (!back_main_flag) {
                    submenu(hStdOut, alg_menu, ALG_MENU_SIZE, &choose_pos);
                    back_main_flag = 0;
                    back_alg_flag = 0;
                    switch (choose_pos) {
                        case 2: {
                            // �����
                            back_main_flag = 1;
                            break;
                        }
                        case 0: {
                            // ���� �������
                            while (!back_alg_flag) {
                                submenu(hStdOut, search_menu, SEARCH_MENU_SIZE, &choose_pos);
                                switch (choose_pos) {
                                    case 0: {
                                        // ������� �����
                                        naive_search(nums, nums_length);
                                        break;
                                    }
                                    case 1: {
                                        // �������� �����
                                        binary_search_menu(nums, nums_length);
                                        break;
                                    }
                                    case 2: {
                                        // �����
                                        back_alg_flag = 1;
                                        break;
                                    }
                                }
                            }
                        }
                        case 1: {
                            // ���� ����������
                            while (!back_alg_flag) {
                                submenu(hStdOut, sort_menu, SORT_MENU_SIZE, &choose_pos);
                                switch (choose_pos) {
                                    case 3: {
                                        // �����
                                        back_alg_flag = 1;
                                        break;
                                    }
                                    case 0: {
                                        // ���������� ���������
                                        int counter = 0;
                                        bubble_sort_menu(nums, nums_length, &counter);
                                        break;
                                    }
                                    case 1: {
                                        // ���������� �����
                                        int counter = 0;
                                        hoara_sorting_menu(nums, nums_length, &counter);
                                        break;
                                    }
                                    case 2: {
                                        // ���������� ��������
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
                // ���� ��������
                while (!back_alg_flag) {
                    submenu(hStdOut, settings_menu, SETTINGS_MENU_SIZE, &choose_pos);
                    switch (choose_pos) {
                        case 3: {
                            // �����
                            back_alg_flag = 1;
                            break;
                        }
                        case 0: {
                            // ���� �������
                            nums = set_array(nums, &nums_length);
                            break;
                        }
                        case 1: {
                            //��������� ������ ���������� �������
                            nums_length = rand() % 11 + 5;
                            nums = gen(nums_length);
                            show_array(nums, nums_length);
                            break;
                        }
                        case 2: {
                            // ����� �������� �������
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
    // ����� ����������
    system("cls");
    printf("  ����-����)!\n  ");

    // ���������� ���������
    system("pause");
    return 0;
}