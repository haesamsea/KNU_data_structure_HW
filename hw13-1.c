#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

void printList(nodePointer head) {
	nodePointer nextnode = head;
	while (nextnode) {
		printf("%4d", nextnode->data);
		nextnode = nextnode->link;
	}
}

void main(void) {
	short int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x=NULL, y=NULL, top=NULL;
	int i, j, n;
	int cnt=0;

	FILE* fp = fopen("e3.txt", "r");

	
	fscanf(fp,"%d ", &n);
	for (i = 0; i <= n; i++) {
		out[i] = TRUE; seq[i] = NULL;
	}

	fscanf(fp,"%d %d", &i, &j);

	while (cnt < n) {
		x = (nodePointer)malloc(sizeof(nodePointer));
		x->data = j; x->link = seq[i]; seq[i] = x;
		x = (nodePointer)malloc(sizeof(nodePointer));
		x->data = i; x->link = seq[j]; seq[j] = x;
		fscanf(fp,"%d %d ", &i, &j);

		cnt++;
	}

	for(int i = 0; i <= n; i++){
		printf("[%d] ", i);
		printList(seq[i]);
		printf("\n");

	}

	//printf("ENTER A PAIR OF NUMBERS(-1 -1 TO QUIT")
	for (i = 0; i <= n; i++) {
		if (out[i]) {
			printf("\nNEW CLASS: %5d", i);
			out[i] = FALSE;
			x = seq[i];
			top = NULL;
			for (;;) {
				while (x) {
					j = x->data;
					if (out[j]) {
						printf("%5d", j); out[j] = FALSE;
						y = x->link; x->link = top; top = x; x = y;
					}
					else x = x->link;
				}
				if (!top)break;
				x = seq[top->data];
				top = top->link;
			}
		}
	}

}