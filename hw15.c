#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	char name[10];
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child > h->heap_size) || (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	element arr[20];
	element arr2[20];
	element arr3[20];
	HeapType* heap;
	int i = 0;
	int number = 0;

	FILE* fp = fopen("in.txt", "r");

	heap = create();
	init(heap);

	for (int i = 1; i <= 9; i++) {
		fscanf(fp, "%s ", arr[i].name);
		fscanf(fp, "%d ", &arr[i].key);
		insert_max_heap(heap, arr[i]);
	}

	printf("Before deleting:\n");
	for (int i = 1; i <= 9; i++) {
		printf("[%s, %d] ",heap->heap[i].name, heap->heap[i].key);
	}

	printf("\nInput number:");
	scanf("%d", &number);

	for (int i = 1; i <= number; i++) {
		arr2[i] = delete_max_heap(heap);
		printf("item(served): (%s,%d)\n", arr2[i].name, arr2[i].key);

	}

	printf("After deleting:\n");

	for (int i = 9-number; i >= 1; i--) {
		arr2[i] = delete_max_heap(heap);
		printf("[%s, %d]", arr2[i].name, arr2[i].key);

	}


	free(heap);
	return 0;

}