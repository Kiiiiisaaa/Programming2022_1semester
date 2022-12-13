#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus"); // без спец. библиотеки кириллица не отображается в консоли
	int age;
	scanf_s("%d", &age); // требуется & перед age
	if (age <= 13) 
		printf("%d - детство", age); // пропущена точка с запятой
	else if (14 <= age < 25)
		printf("%d - молодость", age); // чтобы вывести int, нужен спецификатор %d или %i
	else if (25 <= age && age < 60)
		printf("%d - зрелость", age);
	else 
		printf("%d - старость", age);
	return 0;
}