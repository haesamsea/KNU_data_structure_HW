#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[1001], visi[1001];
    FILE* fp = fopen("c.txt", "r"), * fp2 = fopen("b.txt", "r");
    for (int i = 0; i < 1001; i++) {
        arr[i] = 0;
        visi[i] = 0;
    }
    // read a.txt
    int aCnt = 0;
    int aList[10001];
    while (!feof(fp)) {
        fscanf_s(fp, "%d", &aList[aCnt++]);
    }
    printf("A(x):");
    for (int i = 0; i < aCnt; i += 2) {
        int coefficient = aList[i], exponent = aList[i + 1];
        visi[exponent] = 1;
        arr[exponent] += coefficient;
        if (aCnt - 2 != i) {
            printf("%dx^%d + ", coefficient, exponent);
        }
        else {
            printf("%dx^%d\n", coefficient, exponent);
        }
    }
    // read b.txt
    int bCnt = 0;
    int bList[10001];
    while (!feof(fp2)) {
        fscanf_s(fp2, "%d", &bList[bCnt++]);
    }
    printf("B(x):");
    for (int i = 0; i < bCnt; i += 2) {
        int coefficient = bList[i], exponent = bList[i + 1];
        visi[exponent] = 1;
        arr[exponent] -= coefficient;
        if (bCnt - 2 != i) {
            printf("%dx^%d + ", coefficient, exponent);
        }
        else {
            printf("%dx^%d\n\n", coefficient, exponent);
        }
    }

    // check zero
    int cCnt = 0;
    int cList[10001];
    // printf all
    for (int i = 0; i < 1001; i++) {
        if (arr[i] == 0)continue;
        if (visi[i] == 1) {
            cList[cCnt++] = arr[i];
            cList[cCnt++] = i;
        }
    }
    printf("C(x):");
    if (cCnt == 0) {
        printf("0");
    }
    else {
        for (int i = 0; i < cCnt; i += 2) {
            int coefficient = cList[i], exponent = cList[i + 1];
            if (cCnt - 2 != i) {
                printf("%dx^%d + ", coefficient, exponent);
            }
            else {
                printf("%dx^%d", coefficient, exponent);
            }
        }
    }

}