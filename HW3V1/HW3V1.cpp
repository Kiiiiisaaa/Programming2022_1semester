#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <math.h>

#define PI 3.1415926535

void intro() {
	printf("Добро пожаловать!");
	Sleep(500);
	system("cls");
	for (int i = 0; i < 2; i++) {
		printf("Загрузка.");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		system("cls");
	}
}

void rectangle_menu(int* mode, float a, float b) {
	int fl = 1;
	while (fl) {
		printf("Меню:\n1. Найти площадь прямоугольника.\n2. Найти периметр прямоугольника.\n3. Найти диагональ прямоугольника.\n4. Вернуться к выбору фигуры.\n0. Выйти\nВвод: ");
		int ans;
		scanf_s("%d", &ans);
		switch (ans) {
		case 1: { printf("Площадь прямоугольника: %.2f\n", (a * b)); break; }
		case 2: { printf("Периметр прямоугольника: %.2f\n", 2 * (a + b)); break; }
		case 3: { printf("Диагональ прямоугольника: %.2f\n", sqrt(pow(a, 2) + pow(b, 2))); break; }
		case 4: { fl = 0;  break; }
		case 0: { *mode = -1; fl = 0; break; }
		}
		if (ans != 4) system("pause");
		system("cls");
	}
}

void rectangle(int* mode) {
	system("cls");
	float a, b;
	printf("Введите две стороны прямоугольника: ");
	scanf_s("%f %f", &a, &b);
	system("cls");
	rectangle_menu(mode, a, b);
}


void triangle_menu(int* mode, float a, float b) {
	int fl = 1;
	while (fl) {
		printf("Меню:\n1. Найти площадь треугольника.\n2. Найти периметр треугольника.\n3. Найти гипотенузу треугольника.\n4. Вернуться к выбору фигуры.\n0. Выйти\nВвод: ");
		int ans;
		scanf_s("%d", &ans);
		switch (ans) {
		case 1: { printf("Площадь прямоугольного треугольника: %.2f\n", (a * b) / 2); break; }
		case 2: { printf("Периметр прямоугольного треугольника: %.2f\n", (a + b + sqrt(pow(a, 2) + pow(b, 2)))); break; }
		case 3: { printf("Гипотенуза прямоугольного треугольника: %.2f\n", sqrt(pow(a, 2) + pow(b, 2))); break; }
		case 4: { fl = 0;  break; }
		case 0: { *mode = -1; fl = 0; break; }
		default: { *mode = -1; fl = 0; break; }
		}
		if (ans != 4) system("pause");
		system("cls");
	}
}

void triangle(int* mode) {
	system("cls");
	float a, b;
	printf("Введите два катета прямоугольного прямоугольника: ");
	scanf_s("%f %f", &a, &b);
	system("cls");
	triangle_menu(mode, a, b);
}


void circle_menu(int* mode, float r) {
	int fl = 1;
	while (fl) {
		printf("Меню:\n1. Найти площадь круга.\n2. Найти длину окружности круга.\n3. Найти диаметр круга.\n4. Вернуться к выбору фигуры.\n0. Выйти\nВвод: ");
		int ans;
		scanf_s("%d", &ans);
		switch (ans) {
		case 1: { printf("Площадь круга: %.2f\n", PI * r * r); break; }
		case 2: { printf("Длина окружности круга: %.2f\n", 2 * PI * r); break; }
		case 3: { printf("Диаметр круга: %.2f\n", 2 * r); break; }
		case 4: { fl = 0;  break; }
		case 0: { *mode = -1; fl = 0; break; }
		default: { *mode = -1; fl = 0; break; }
		}
		if (ans != 4) system("pause");
		system("cls");
	}
}

void circle(int* mode) {
	system("cls");
	float r;
	printf("Введите радиус круга: ");
	scanf_s("%f", &r);
	system("cls");
	circle_menu(mode, r);
}


void figure_choose_menu(int* mode) {
	int ans;
	int fl = 1;
	while (fl and *mode != -1) {
		printf("Выбор фигуры:\n1. Прямоугольник.\n2. Треугольник.\n3. Круг.\n0. Выйти из приложения\nВвод: ");
		scanf_s("%d", &ans);
		switch (ans) {
		case 1: { rectangle(mode); break; };
		case 2: { triangle(mode); break; };
		case 3: { circle(mode); break; };
		case 0: { *mode = -1; fl = 0; break; }
		default: { *mode = -1; fl = 0; break; }
		}
	}
}


int main() {
	setlocale(LC_CTYPE, "rus");
	int mode = 0;
	intro();
	while (mode != -1) figure_choose_menu(&mode);
	system("cls");
	system("pause");
}