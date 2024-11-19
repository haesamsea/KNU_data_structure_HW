#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)= (t))

int n;

typedef struct {
    char name[101];
    int age;
} member;

void insert(member e, member a[], int i)
{
    a[0] = e;
    while (e.age > a[i].age) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

void insertionSort(member a[], int n)
{/* sort a[l:n] into nondecreasing order */
    int j;
    for (j = 1; j <= n; j++) {
        member temp = a[j];
        insert(temp, a, j - 1);
    }
}

void quickSort(member a[], int left, int right) {
    int pivot, i, j;
    member temp;
    if (left < right) {
        i = left; j = right + 1;
        pivot = a[left].age;
        do {

            do i++; while (a[i].age > pivot);
            do j--; while (a[j].age < pivot);
            if (i < j) SWAP(a[i], a[j], temp);
        } while (i < j);
        SWAP(a[left], a[j], temp);
        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
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
    }

    quickSort(arr, 0, N);
    printf("Quick Sort\n");
    for (int i = 0; i < N; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
    free(arr);
    return 0;
}