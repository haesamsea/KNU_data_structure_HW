//Circular queue
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100


typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

int flag = 0;

void error(char*message){
	fprintf(stderr, "%s\n", message);
	flag = 1;
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

void queue_print(QueueType* q, int number) {
	
	if (!is_empty(q)) {
		printf("Queue :");
		int i = q->front;
		do {
			i = (i + 1) % (number);
			printf(" %d ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	else {
		printf("Circular queue is empty");
	}
	printf("\n");
}

int is_full(QueueType* q, int number) {
	 return  ((q->rear+1) % number == q->front);
}

int is_empty(QueueType* q) {

	 return (q->front == q->rear);
}

void enqueue(QueueType* q, int item, int number) {
	if (is_full(q,number)) {
		error("queue full: cannot add");
	}
	q->rear = (q->rear + 1) % number;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q, int number)
{
	if (is_empty(q)) {
		error("queue empty: cannot delete");
	}
	q->front = (q->front + 1) % number;
	return q->data[q->front];
	
}

int peek(QueueType* q, int number)
{
	if (is_empty(q)) 
		error("큐가 공백상태입니다");
	return q->data[q->front+1] % number;

}


int main() {
	QueueType* queue;
	int element=0;
	char arr, arr2, arr3;
	int number=0, number2=0, number3=0;

	FILE* fp1 = fopen("in1.txt", "r");
	
	fscanf(fp1, "%d ", &element); //큐 개수
	printf("Queue size: %d\n", element);

	queue = (QueueType *) malloc(sizeof(QueueType) * element);

	init_queue(queue);
	while (!is_full(queue,element) || !feof(fp1) || !is_empty(queue)) 
	{
			fscanf(fp1, "%c ", &arr);
			//printf("%c ", arr);
			if (arr == 'a') {
				fscanf(fp1, "%d ", &number);
				enqueue(queue, number, element);
				if (flag != 0) break;
				queue_print(queue, element);
			}
			else if (arr == 'd') {
				dequeue(queue,element);
				if (flag != 0) break;
				queue_print(queue, element);
			}
			number = 0;
			
	}
	printf("==================\n");
	fclose(fp1);
	free(queue);
	flag = 0;
	int element2 = 0;
	
	FILE* fp2 = fopen("in2.txt", "r");
	
	fscanf(fp2, "%d ", &element2); //큐 개수
	printf("Queue size: %d\n", element2);
	queue = (QueueType*)malloc(sizeof(QueueType) * element2);
	init_queue(queue);
	while (!is_full(queue, element2) || !feof(fp2) || !is_empty(queue))
	{
		fscanf(fp2, "%c ", &arr2);
		if (arr2 == 'a') {
			fscanf(fp2, "%d ", &number2);
			enqueue(queue, number2, element2);
			if (flag != 0) break;
			queue_print(queue, element2);
		}
		else if (arr2 == 'd') {
			
			dequeue(queue, element2);
			//printf("\nflag : %d ", flag);
			if (flag != 0) break;
			queue_print(queue, element2);
		}
		number2 = 0;
	}
	fclose(fp2);
	free(queue);

	printf("==================\n");
	flag = 0;
	int element3 = 0;

	FILE* fp3 = fopen("in3.txt", "r");

	fscanf(fp3, "%d ", &element3); //큐 개수
	printf("Queue size: %d\n", element3);
	queue = (QueueType*)malloc(sizeof(QueueType) * element3);
	init_queue(queue);

	while (!is_full(queue, element3) || !is_empty(queue))
	{
		while (!feof(fp3))
		{
			fscanf(fp3, "%c ", &arr3);
			if (arr3 == 'a') {
				fscanf(fp3, "%d ", &number3);
				enqueue(queue, number3, element3);
				if (flag != 0) break;
				queue_print(queue, element3);
			}
			else if (arr3 == 'd') {

				dequeue(queue, element3);
				//printf("\nflag : %d ", flag);
				if (flag != 0) break;
				queue_print(queue, element3);
			}
		}
	}
	free(queue);
	fclose(fp3);
	
}