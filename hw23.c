#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef int element;

typedef struct {
	char face;
	int num;
}card;

typedef struct {
	card data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, card item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

card dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 2

void radix_sort(card list[], int n) {
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	int number = 0;
	int k = 0;
	card temp[5];
	card real;

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);
	
	//숫자 정렬
	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i].num / factor) % 10], list[i]);
		for (b = i = 0; b < BUCKETS; b++)
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;
	}

	//1 뒤로 보내기
	for (d = i = 0; d < n; d++)
		if (list[d].num == 1) temp[i++] = list[d];
	for (d = 0; d < n - i; d++)
		list[d] = list[d + i];
	for (d = n - i; d < n; d++)
		list[d] = temp[k++];

	//문자 정렬

	for (i = 0; i < n; i++)
	{
		if (list[i].face == 'C')
			enqueue(&queues[0], list[i]);
		else if (list[i].face == 'D')
			enqueue(&queues[1], list[i]);
		else if (list[i].face == 'H')
			enqueue(&queues[2], list[i]);
		else if (list[i].face == 'S')
			enqueue(&queues[3], list[i]);
	}
	for (b = i = 0; b < 4; b++)
		while (!is_empty(&queues[b]))
			list[i++] = dequeue(&queues[b]);
}

#define SIZE 10

int main(void) {
	card list[SIZE];
	FILE* fp = fopen("in.txt", "r");
	int i = 0, num = 0;
	fscanf(fp, "%d ", &num);

	while (!feof(fp)) {
		fscanf(fp, "%c %d\n", &list[i].face, &list[i].num);
		i++;
	}

	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++){
		if (list[i].face == 'C') {
			printf("( club");
			if (list[i].num == 11) printf(".   J)\n");
			else if (list[i].num == 12) printf(".   Q)\n");
			else if (list[i].num == 13) printf(".   K)\n");
			else printf(". %3d)\n", list[i].num);
		}
		if (list[i].face == 'S') {
			printf("(spade");
			if (list[i].num == 11) printf(".   J)\n");
			else if (list[i].num == 12) printf(".   Q)\n");
			else if (list[i].num == 13) printf(".   K)\n");
			else printf(". %3d)\n", list[i].num);
		}
		if (list[i].face == 'D') {
			printf("(  dia");
			if (list[i].num == 11) printf(".   J)\n");
			else if (list[i].num == 12) printf(".   Q)\n");
			else if (list[i].num == 13) printf(".   K)\n");
			else printf(". %3d)\n", list[i].num);
		}
		if (list[i].face == 'H') {
			printf("(heart");
			if (list[i].num == 11) printf(".   J)\n");
			else if (list[i].num == 12) printf(".   Q)\n");
			else if (list[i].num == 13) printf(".   K)\n");
			else printf(". %3d)\n", list[i].num);
		}
	}
	printf("\n"); 
	return 0;
}
