#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 8
int sorted[MAX_SIZE];

typedef struct member {
    char name[10];
    int key;
}member;

void merge(member list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* 분할 정렬된 list의 합병 */
    while (i <= mid && j <= right) {
        if (list[i].key <= list[j].key)
            sorted[k++] = list[i++].key;
        else
            sorted[k++] = list[j++].key;
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l].key;
    }
    // 남아 있는 값들을 일괄 복사
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l].key;
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l].key = sorted[l];
    }
}

// 합병 정렬
void merge_sort(member list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
            merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}

int main(void)
{
    int N;
    FILE* fp = fopen("in.txt", "r");
    fscanf(fp, "%d ", &N);

    member* arr = (member*)malloc(N * sizeof(member));

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%s %d ", arr[i].name, &arr[i].key);
        //printf("%s %d\n", arr[i].name, arr[i].age);
    }
    merge_sort(arr, 0, N - 1);
    printf("[after merge sort]\n");
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%5s: %2d\n", arr[i].name, arr[i].key);
    }
    free(arr);
    return 0;
}