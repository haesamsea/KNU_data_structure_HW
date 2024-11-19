#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 50


typedef struct {                         //행렬 원소를 저장하기 위한 구조체 term 정의
	int row;
	int col;
	int value;
} term;

void fast_transpose(term a[], term b[]);

void fast_transpose(term a[], term b[]) {
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	if (numTerms > 0) {
		for (i = 0; i < numCols; i++) {
			rowTerms[i] = 0;
		}
		for (i = 1; i <= numTerms; i++) {
			rowTerms[a[i].col]++;
			startingPos[0] = 1;
		}
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (i = 1; i <= numTerms; i++) {
			j = startingPos[a[i].col]++;
			b[j].row = a[i]. col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;

		}
	}

	for (i = 0; i <= numTerms; i++)
		printf("( %d, %d, %d)\n", b[i].row, b[i].col, b[i].value);
	printf("\n\n");
}



int main(void) {

	int i, j;
	int a,b;
	int Ak[100];
	int Bk[100];
	term A[20];
	term Achange[20];
	term B[20];
	term Bchange[20];

	FILE* fp = fopen("a1.txt", "r"), *fp2 = fopen("b1.txt","r");

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
	A[0].value = cnt2;

	
	//for (i = 0; i <= cnt2; i++)
		//printf("( % d, % d, % d)\n", A[i].row, A[i].col, A[i].value);
	//printf("\n");

	//printf("( % d, % d, % d)\n", b, a, cnt2);

	fast_transpose(A, Achange);
	////////////////////////////////////////
	a = 0, b = 0, cnt=0, cnt2=0;


	fscanf(fp2, "%d %d", &a, &b);

	B[0].row = a, B[0].col = b;

	int ccnt = 0, ccnt2 = 1;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			fscanf(fp2, "%d", &Bk[ccnt]);
			if (Bk[ccnt] != 0)
			{
				B[ccnt2].value = Bk[ccnt], B[ccnt2].row = i, B[ccnt2].col = j, ccnt2++;
			}
			cnt++;
		}
	}
	ccnt2--;
	B[0].value = ccnt2;


	//for (i = 0; i <= ccnt2; i++)
	//printf("( % d, % d, % d)\n", B[i].row, B[i].col, B[i].value);
	//printf("\n");

	//printf("( % d, % d, % d)\n", b, a, ccnt2);


	fast_transpose(B, Bchange);

	


	return 0;
}