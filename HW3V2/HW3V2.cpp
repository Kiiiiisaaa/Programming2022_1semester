#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_CTYPE, "rus");
	printf("Количество элементов: ");
	int n;
	scanf_s("%d", &n);
	printf("Введите элементы: ");
	int cur, sum = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &cur);
		sum += cur * cur;
	}
	printf("Сумма квадратов элементов: %d\n", sum);
	system("pause");
	return 0;
}