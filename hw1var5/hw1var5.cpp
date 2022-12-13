#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	printf("Число 1: ");
	float a, b;
	scanf_s("%f", &a);
	printf("Число 2: ");
	scanf_s("%f", &b);
	printf("Сумма: %.2f\n", a + b);
	printf("Разность: %.2f\n", a - b);
	printf("Произведение: %.2f\n", a * b);
	printf("Чатное: %.2f\n", (float)a/(float)b);
	printf("Среднее арифметическое квадратов: %.2f\n", float(pow(a, 2) + pow(b, 2))/(float)2);
	printf("Среднее арифметическое модулей: %.2f\n", float(fabsf(a) + fabsf(b))/(float)2);
	printf("Целый остаток от деления:: %.2f\n", (int)a % (int)b);
	system("pause");
}