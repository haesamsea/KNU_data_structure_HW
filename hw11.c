#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;


typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	} 
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if(a->expon == b -> expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	if (plist->head == NULL) {
		printf("empty list!\n");
	}
	else {
	for (; p; p = p->link) {
		printf("< %2d, %2d > ", p->coef, p->expon);
	}
	printf("\n");
	}
}


int main() {

	ListType* list1, * list2, * list3;
	ListNode polyA, polyB;

	list1 = create();
	list2 = create();
	list3 = create();

	FILE* fp1 = fopen("padd1.txt", "r");
	FILE* fp2 = fopen("padd2.txt", "r");

	while (!feof(fp1)) {
		fscanf(fp1, "%d %d ", &polyA.coef, &polyA.expon);
		insert_last(list1, polyA.coef, polyA.expon);
	}

	while (!feof(fp2)) {
		fscanf(fp2, "%d %d ", &polyB.coef, &polyB.expon);
		insert_last(list2, polyB.coef, polyB.expon);
	}

	
	printf("    polyA : ");
	poly_print(list1);
	printf("    polyB : ");
	poly_print(list2);

	poly_add(list1, list2, list3);
	printf("poly(A+B) : ");
	poly_print(list3);

	printf("\nafter erasing...\n");

	while (list1 == NULL) {
		free(list1);
	}
	while (list1 == NULL) {
		free(list2);
	}
	while (list1 == NULL) {
		free(list3);
	}


	list1->head = NULL;
	poly_print(list1);
	list2->head = NULL;
	poly_print(list2);
	list3->head = NULL;
	poly_print(list3);
	

	return 0;
}