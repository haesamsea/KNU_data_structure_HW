#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(LinkedQueueType* q) {
	return(q->front == NULL);
}

int is_full(LinkedQueueType* q) {
	return 0;
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;

	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, " Waiting. Empty");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}

void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	if (q->front ==  0) {
		printf(" Empty");
	}
	else{
	for (p = q->front; p != NULL; p = p->link)
		printf(" [ %d]", p->data);
	}
	printf("\n");
}

int main(void) {

	LinkedQueueType X;
	LinkedQueueType Y;
	LinkedQueueType Z;
	LinkedQueueType W;

	char person[30];

	char man;
	int number = 0;

	int cnt = 0;

	init(&X);
	init(&Y);
	init(&Z);
	init(&W);

	FILE* fp = fopen("in.txt", "r");
	

	while (!feof(fp)) {
		fscanf(fp, "%s ", &person[cnt]);
		if (person[cnt] == 'X') {
			fscanf(fp, "%d ", &number);
			enqueue(&X, number);
			printf("(Insert X %d) ==> X:", number);
			print_queue(&X);

		}
		else if (person[cnt] == 'Y') {
			fscanf(fp, "%d ", &number);
			enqueue(&Y, number);
			printf("(Insert Y %d) ==> Y:", number);
			print_queue(&Y);
		
		}
		else if (person[cnt] == 'Z') {
			fscanf(fp, "%d ", &number);
			enqueue(&Z, number);
			printf("(Insert Z %d) ==> Z:", number);
			print_queue(&Z);
		
		}
		else if (person[cnt] == 'W') {
			fscanf(fp, "%d ", &number);
			enqueue(&W, number);
			printf("(Insert W %d) ==> W:", number);
			print_queue(&W);

		}
		else if (person[cnt] == 'D') {
			fscanf(fp, "%c ", &man);
			if (man == 'X') {
				printf("(Delete X) ==>", number);
				if (X.front != X.rear) {
					printf(" person %d,", dequeue(&X));
					if (X.front <= X.rear)
						printf(" %d searved.", dequeue(&X));
					else if (X.front == X.rear)
						printf(" searved.");
				}
				else if (X.front == X.rear)
				{
					//printf("ddd\n");
					printf(" person %d searved.", dequeue(&X));
				}
				else if (X.front == X.rear)
					printf(" Waiting.");
				
				
				print_queue(&X);

			}
			else if (man == 'Y') {
				printf("(Delete Y) ==>", number);
				if (Y.front + 2 != Y.rear)
					printf(" person %d, %d searved.", dequeue(&Y), dequeue(&Y));
				else if (Y.front == Y.rear)
					printf(" person %d searved.", dequeue(&Y));
				else if (Y.front == Y.rear)
					printf(" Waiting.");


				
				print_queue(&Y);

			}
			else if (man == 'Z') {

				printf("(Delete Z) ==>", number);
				if (Z.front +2 !=  Z.rear){
					printf(" person %d", dequeue(&Z));
					if (Z.front != Z.rear)
						printf(", %d searved", dequeue(&Z));
					else if (Z.front == Z.rear)
						printf(" searved.");
				}
				else if (Z.front == Z.rear)
					printf(" person %d searved.", dequeue(&Z)); 
				else if (Z.front == Z.rear)
					printf(" Waiting.");


				/*dequeue(&Z);
				dequeue(&Z);*/
				print_queue(&Z);

			}
			else if (man == 'W') {
				printf("(Delete W) ==>", number);
				if (W.front + 2 <= W.rear)
					printf(" person %d, %d searved.", dequeue(&W), dequeue(&W)); 
				else if (W.front + 1 == W.rear)
					printf(" person %d searved.", dequeue(&W));
				else if (W.front == W.rear)
					printf(" Waiting.");


				print_queue(&W);

			}
			//enqueue(&D, number);
			number = 0;
			cnt++;
			
		}

	}



	return 0;
}