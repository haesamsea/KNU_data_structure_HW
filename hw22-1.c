#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
int N = 1;

typedef struct element {
	char name[50];
	int key;
}element;
element a[100];

void swap(element* a, element* b) {
	element temp = *a;
	*a = *b;
	*b = temp;
}

void adjust(element a[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key > a[child + 1].key))
			child++;
		if (rootkey < a[child].key)
			break;
		else {
			a[child / 2] = a[child];
			child *= 2;
			}
		}
	printf("adjust %d: rootkey %d\n", N++, rootkey);
	a[child / 2] = temp;
}


void heapSort(element* a, int n) {
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	for (i = n - 1; i > 0; i--) {
		SWAP(a[1], a[i + 1],temp);
		adjust(a, 1, i);
	}
}

void printlist(element* a, int s) {
	for (int i = 1; i <= s; i++) {
		printf("%+6s: %3d\n", a[i].name, a[i].key);
	}
}


int main(void) {
	FILE* fp = fopen("in.txt", "r");
	int i = 1, num = 0;
	fscanf(fp, "%d", &num);
	while (!feof(fp)) {
		fscanf(fp, "%s %d", a[i].name, &a[i].key);
		i++;
	}
	fclose(fp);

	printf("[Heap sort]\n");
	heapSort(a, num);
	printlist(a, num);
}