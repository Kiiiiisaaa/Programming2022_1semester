#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, c;
	printf("Введите ваши оценки: ");
	scanf_s("%d %d %d", &a, &b, &c);
	if (a == b && b == c && c == 5) { printf("Отличник"); }
	else if (a == -1 || b == -1 || c == -1) { printf("Не сдал"); }
	else if (a == 2 || b == 2 || c == 2) { printf("Двоечник"); }
	else if (a == 3 || b == 3 || c == 3) { printf("Троечник"); }
	else { printf("Хорошист");
}
}
