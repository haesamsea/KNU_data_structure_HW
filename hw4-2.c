#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {

	int i = 0, j = 0, k = 0;
	int*** arr;

	printf("A[I][J][K]...\n");
	printf("Input I: ");
	scanf("%d", &i);
	printf("Input J: ");
	scanf("%d", &j);
	printf("Input K: ");
	scanf("%d", &k);

	arr = (int***)malloc(sizeof(int**) * i);

	for (int a = 0; a < i; a++)
	{

		arr[a] = (int**)malloc(sizeof(int*) * j); 
		for (int b = 0; b < j; b++)
		{
			arr[a][b] = (int*)malloc(sizeof(int) * k);
		}
	}

	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < j; y++)
		{
			for (int z = 0; z < k; z++)
			{
				arr[x][y][z] = x + y + z;
			}
		}
	}

	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < j; y++)
		{
			for (int z = 0; z < k; z++)
			{
				printf("A[%d][%d][%d]=%d ",x,y,z ,arr[x][y][z]);
			}
			printf("\n");
		}
		printf("\n");
	}
		  for (int x = 0; x < i; x++)
		  {
			  for (int y = 0; y < j; y++)
			  {
				  free(arr[x][y]); 
				  
			  }
		  }

		  for (int x = 0; x < i; x++)
		  {
			  free(arr[x]);  
		  }
		  free(arr); 
		 
		  return 0;


}