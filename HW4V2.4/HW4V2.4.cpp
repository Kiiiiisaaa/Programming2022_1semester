#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


int count_chars(char* string, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) if (string[i] != '\n' && string[i] != ' ') count++;
	return count;
}

int count_lower(char* string, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) if (islower(string[i])) count++;
	return count;
}

int count_upper(char* string, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) if (isupper(string[i])) count++;
	return count;
}

int count_words(char* string, int length) {
	int count = 0;
	char cur = 'a', prev = 'a';
	for (int i = 0; i < length; i++) {
		prev = cur;
		cur = string[i];
		if (isalpha(prev) && isspace(cur)) count++;
	}
	if (isalpha(cur)) count++;
	return count;
}

int main() {
	setlocale(LC_ALL, "rus");
	int length = 1;
	char* string = (char*)malloc(length * sizeof(char)), current;
	printf("Введите строку: ");
	while ((current = getchar()) != '\n') {
		string[length - 1] = current;
		length++;
		string = (char*)realloc(string, length);
	}
	length--;
	printf("Количество значимых знаков: %d\n", count_chars(string, length));
	printf("Количество строчных букв: %d\n", count_lower(string, length));
	printf("Количество заглавных букв: %d\n", count_upper(string, length));
	printf("Количество слов: %d\n", count_words(string, length));
	return 0;
}