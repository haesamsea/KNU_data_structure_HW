#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	char name[50];
	int key;
}element;
element a[100];

void printlist(element* a, int s) {
	for (int i = 0; i < s; i++) {
		printf("%+6s: %3d\n", a[i].name, a[i].key);
	}
}

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m && j <= n) {
		if (initList[i].key >= initList[j].key) {
			mergedList[k++] = initList[i++];
		}
		else {
			mergedList[k++] = initList[j++];
		}
	}
	if (i > m) {
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	}
	else {
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
	}
}

void mergePass(element* initList, element* mergedList, int n, int s) {
	int i, j;
	for (i = 0; i <= n - 2 * s + 1; i += 2 * s) {
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	}
	if (i + s - 1 < n) {
		merge(initList, mergedList, i, i + s - 1, n);
	}
	else {
		for (j = i; j <= n; j++) {
			mergedList[j] = initList[j];
		}
	}
}

void mergeSort(element* a, int n) {
	int s = 1;
	element extra[100];

	while (s < n) {
		mergePass(a, extra, n, s);
		printlist(a, s);
		printf("-----------------\n");
		s *= 2;
		mergePass(extra, a, n, s);
		printlist(a, s);
		printf("-----------------\n");
		s *= 2;
	}
}

int main(void) {
	FILE* fp = fopen("in.txt", "r");
	int i = 0, num = 0;
	fscanf(fp, "%d", &num);
	while (!feof(fp)) {
		fscanf(fp, "%s %d", a[i].name, &a[i].key);
		i++;
	}
	fclose(fp);

	printf("[Iterative merge sort]\n");
	mergeSort(a, num);
	printlist(a, num);
}