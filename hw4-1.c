#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int firstfp[5];
	int secondfp[7];
	int cnt = 0, num = 0;
	int result[11] = {0};

	FILE* fp = fopen("in1.txt", "r"), * fp2 = fopen("in2.txt", "r");


	while (!feof(fp)) {
		fscanf_s(fp, "%d", &firstfp[cnt]);
		cnt++;
	}

	cnt = 0;
	while (!feof(fp2)) {
		fscanf_s(fp2, "%d", &secondfp[cnt]);
		cnt++;
	}

	int i = 0, j = 0;
	for (int num = 0; num < 11; num++)
		{
		
		if (firstfp[i] < 0 || secondfp[j] < 0)
		{

			if (firstfp[i] < 0) {
				result[num] = secondfp[j];
				j++;
			}

			else if (secondfp[j] < 0) {
				result[num] = firstfp[i];
				i++;
			}
			}
		else {

			if (firstfp[i] == secondfp[j]) {
				result[num] = firstfp[i];
				i++; j++;
			}

	
			else if (firstfp[i] < secondfp[j]) {
				result[num] = firstfp[i];
				i++;

			}
			else if (firstfp[i] > secondfp[j]) {
				result[num] = secondfp[j];
				j++;
			}

		}

	}
	
	for (int i = 0; i < 11; i++) {
		printf("%d ", result[i]);
	}


	return 0;
}