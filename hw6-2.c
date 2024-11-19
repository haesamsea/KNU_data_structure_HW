#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 50


typedef struct {                         //행렬 원소를 저장하기 위한 구조체 term 정의
	int row;
	int col;
	int value;
} term;

int main(void) {

	int i, j;
	int a, b;
	int t, v;
	int Ak[200];
	int Bk[200];
	int Ck[200];
	term A[200];
	term B[200];
	term C[200];

	FILE* fp = fopen("a2.txt", "r"), * fp2 = fopen("b2.txt", "r");

	fscanf(fp, "%d %d", &a, &b);

	A[0].row = a, A[0].col = b;

	int cnt = 0, cnt2 = 1;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {

			fscanf(fp, "%d", &Ak[cnt]);

			if (Ak[cnt] != 0)
			{
				A[cnt2].value = Ak[cnt], A[cnt2].row = i, A[cnt2].col = j, cnt2++;
			}
			cnt++;
		}
	}
	cnt2--;
	//printf("%d %d", cnt, cnt2);

	A[0].value = cnt2;
	//====================================================


	fscanf(fp2, "%d %d", &t, &v);

	B[0].row = t, B[0].col = v;

	int ccnt = 0, ccnt2 = 1;

	for (i = 0; i < t; i++) {
		for (j = 0; j < v; j++) {
			fscanf(fp2, "%d", &Bk[ccnt]);
			if (Bk[ccnt] != 0)
			{
				B[ccnt2].value = Bk[ccnt], B[ccnt2].row = t, B[ccnt2].col = v, ccnt2++;
			}
			ccnt++;
		}
	}
	ccnt2--;

//	printf(" %d %d", ccnt, ccnt2);
	B[0].value = ccnt2;

	//==================================================

	for (i = 0; i < ccnt; i++)
	{
		Ck[i] = Ak[i] - Bk[i];
	}

	//======================================================


	C[0].row = 5, C[0].col = 9;

	int cccnt = 0, cccnt2 = 1;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 9; j++) {
			if (Ck[cccnt] != 0)
			{
				C[cccnt2].value = Ck[cccnt], C[cccnt2].row = i, C[cccnt2].col = j, cccnt2++;
			}
			cccnt++;
		}
	}
	cccnt2--;
	
	C[0].value = cccnt2;

	for (i = 0; i <= cccnt2 ; i++)
		printf("( %d, %d, %d)\n", C[i].row, C[i].col, C[i].value);
	printf("\n\n");



	return 0;
}