#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)

int main() {
	int number = 0;
	int array[7];

	printf("찾으려는 숫자:");
	scanf("%d", &number);

	FILE* fp = fopen("in.txt", "r");
	for (int i = 0; i <= 6; i++) {
		fscanf(fp,"%d", &array[i]);
	}
	

	printf("iterative binary search의 결과>>");
	if(search_binary(array,number,0,6) == -1)
		printf("fail");
	else
		printf("success");
	
	printf("\n");
	
	printf("sequential search의 결과>>");
	if (binsearch(array, number, 0, 6) == -1)
		printf("fail");
	else
		printf("success");
}

int search_binary(int list[], int key, int low, int high) {
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;
		switch (COMPARE(list[middle], key)) {
		case -1: low = middle + 1;
			break;
		case 0: return middle;
		case 1: high = middle - 1;
		}
	}
	return -1;
}

int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while  (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
			case -1:return binsearch(list, searchnum, middle + 1, right);
			case 0: return middle;
			case 1: return binsearch(list, searchnum, left, middle - 1);
		} 
	}
	return -1;
}