#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM 10


struct node {
	int num;
	struct node* next;
};

typedef struct node Node;
typedef Node* Link;

void printList(Link);
Link appendNode(Link, Link);
Link createNode(int);

void main() {
	int i=0;
	Link head = NULL, cur=0;

	FILE* fp = fopen("in4.txt", "r");
	while (!feof(fp)) {
		fscanf(fp , "%d ", &i);
		cur = createNode(i);
		head = appendNode(head,cur);
		//printf("%d ", cur);
	}
	//srand(time(NULL));
	
	printList(head);
	puts("");
}

Link appendNode(Link head, Link cur) {
	Link nextnode = head;
	if (!head) {
		head = cur;
		return head;
	}
	/*while (nextnode->next) {
		nextnode = nextnode->next;
	}*/
	head = cur;
	cur->next = nextnode;
	return head;
}

void printList(Link head) {
	Link nextnode = head;
	while (nextnode) {
		printf("%d ", nextnode->num);
		nextnode = nextnode->next;
	}
}

Link createNode(int number) {
	Link cur = (Node*)malloc(sizeof(Node));
	cur->num = number;
	cur->next = NULL;

	return cur;
}