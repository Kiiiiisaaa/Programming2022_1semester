#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	float x, y, z;
	setlocale(LC_ALL, "Rus");
	printf("Введите x, y, z: ");
	scanf_s("%f %f %f", &x, &y, &z);
	if (x != y && y != z && x != z) {
		if (x > y && x > z) {
			z += x;
		}
		else if (y > x && y > z) {
			z += y;
		}
		else {
			z = pow(z, 2);
		}
		printf("%f", z);
	}
	else {
		if (x == y && y == z) {
			printf("Все переменные равны");
		}
		else {
			if (x == y) { printf("x = y"); }
			else if (y == z) { printf("y = z"); }
			else if (x == z) { printf("x = z"); }
		}
	}
}