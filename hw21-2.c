#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20


typedef struct member {
	char name[10];
	int age;
}member;

member temp[MAX_SIZE];
int result[20];
int n = 0;


void merge(member* list, int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	result[n] = j;
	printf("mid: %d\n", result[n]);
	//member person;
	while (i <= mid && j <= right) {
		if (list[i].age >= list[j].age) temp[k++] = list[i++];
		else temp[k++] = list[j++];
	}
	while (i <= mid) temp[k++] = list[i++];
	while (j <= right) temp[k++] = list[j++];

	for (l = left; l <= right; l++)
		list[l] = temp[l];
	n++;
}

void merge_sort(member *list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
		
	}
}


int main(void)
{
	int N;
	FILE* fp = fopen("in.txt", "r");
	fscanf(fp, "%d ", &N);

	member* arr = (member*)malloc(N * sizeof(member));

	for (int i = 0; i < N; i++) {
		fscanf(fp, "%s %d ", arr[i].name, &arr[i].age);
		//printf("%s %d\n", arr[i].name, arr[i].age);
	}
	merge_sort(arr, 0, N - 1);

	printf("[Recursive merge sort]\n");

	for (int i = n-1; i >= 0; i--) {
		printf("  mid: %2d\n", result[i]);
	}	
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%5s: %2d\n", arr[i].name, arr[i].age);
	}
	free(arr);
	return 0;
}