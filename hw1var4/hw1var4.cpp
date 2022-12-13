#include <math.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	printf("Ввод: ");
	float a;
	scanf_s("%f", &a);
	printf("Результат: \nОбъем: %f\nПлощадь полной поверхности: %f\nПлощадь боковой поверхности: %f", pow(a, 3), 6 * pow(a, 2), 4 * pow(a, 2));
}
