#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int findmin(int* arr, int size);

int main() {

	int array[8];
	int num;

	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%d", &num);

	for (int i = 0; i < num; i++) {
		fscanf(fp, "%d", &array[i]);
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\nMin : %d", findmin(array, num));

	return 0;
}

int findmin(int* arr, int size) {
	int min;
	if (size == 0)
		return arr[0];

	min = findmin(arr, size-1);

	if (min > arr[size-1])
		return arr[size-1];
	else return min;
}