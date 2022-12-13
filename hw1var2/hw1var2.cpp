#include <stdio.h>

int main() {
	int i;
	scanf_s("%i", &i);
	printf("1: %i\n2: %i\n3: %i", i + 1, i + 2, i + 3);
}