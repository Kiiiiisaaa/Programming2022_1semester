#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


void merge(int* nums, int length, int* counter) {
	int* scratch = (int*)malloc(length * sizeof(int));
	merge_sorting(nums, scratch, 0, length - 1, counter);
}

void merge_sorting(int* nums, int* scratch, int start, int end, int* counter) {
	if (start == end) return;
	int midpoint = (start + end) / 2;

	merge_sorting(nums, scratch, start, midpoint, counter);
	merge_sorting(nums, scratch, midpoint + 1, end, counter);
	int left_index = start;
	int right_index = midpoint + 1;
	int scratch_index = left_index;
	while (left_index <= midpoint && right_index <= end) {
		if (nums[left_index] <= nums[right_index]) {
			scratch[scratch_index] = nums[left_index];
			*counter = *counter + 1;
			left_index++;
		}
		else {
			scratch[scratch_index] = nums[right_index];
			*counter = *counter + 1;
			right_index++;
		}
		scratch_index++;
	}
	for (int i = left_index; i <= midpoint; i++) {
		scratch[scratch_index] = nums[i];
		*counter = *counter + 1;
		scratch_index++;
	}
	for (int i = right_index; i <= end; i++) {
		scratch[scratch_index] = nums[i];
		*counter = *counter + 1;
		scratch_index++;
	}
	for (int i = start; i <= end; i++) nums[i] = scratch[i];
}

void merge_sorting_menu(int* nums, int length, int* counter) {
	system("cls");
	printf("  === Сортировка слиянием ===\n");
	printf("  Исходный массив: ");
	(length <= 15) ? print_array(nums, length) : printf("%d элементов", length);
	merge(nums, length, counter);
	if (length <= 15) { printf("\n  Отсортированный массив: "); print_array(nums, length); }
	printf("\n  Произведено перестановок: %d", *counter);
	printf("\n  ");
	system("pause");
}