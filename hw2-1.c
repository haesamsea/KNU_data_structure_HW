#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1001
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void sort(int[], int n);

void main(void) {

	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	printf("     n     time\n");
	for (n = 0; n <= 1000; n += step)
	{
		for (i = 0; i < n; i++)
			a[i] = n - i;

		start = clock();
		sort(a, n);


		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d   %f\n", n, duration);
		if (n == 100) step = 100;
	}
}

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = 1;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}