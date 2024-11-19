#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct node {
	struct node* next;
	int data;
	int size;
}node;

typedef node* element;

typedef struct {
	element data[MAX_SIZE];
	int front, rear;
}QueueType;

typedef struct Tree {
	node nodes;
	struct nodes* input;
	struct Tree* left;
	struct Tree* right;
	int data;
}Tree;

node* root = NULL;
int size = 0;


void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

void level_order(Tree* ptr) {
	QueueType q;
	init_queue(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" %c ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}


node* insert(node* root, int data) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = data;
		size++;
		return root;
	}
	else {
		root->next = insert(root->next, data);
		return root;
	}
}

void preorder(Tree* tree) {
	if (tree) {
		printf(" %c ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(Tree* tree) {
	if (tree != NULL) {
		inorder(tree->left);
		printf(" %c ", tree->data);
		inorder(tree->right);
	}
}

void postorder(Tree* tree) {
	if (tree != NULL) {
		postorder(tree->left);
		postorder(tree->right);
		printf(" %c ", tree->data);
		
	}
}

//void print2();

int main() {
	int inputNum = 97;
int key = 0;
	//printf("input data num : ");
	//scanf_s("%d", &inputNum);
	Tree binaryTree[MAX_SIZE];
	for (int i = 1; i <= 10; i++) {
		
		if (i != 10) {
			root = insert(root, inputNum);
			inputNum++;
			binaryTree[i].data = root->data;
			binaryTree[i].left = NULL;
			binaryTree[i].right = NULL;
			root = root->next;

			if (i % 2 == 0) {
				binaryTree[i / 2].left = &binaryTree[i];
			}
			else {
				binaryTree[i / 2].right = &binaryTree[i];
			}
		}
		else {
			printf("input data num : ");
			scanf_s("%c", &key);
			root = insert(root, key);

			binaryTree[i].data = root->data;
			binaryTree[i].left = NULL;
			binaryTree[i].right = NULL;
			root = root->next;

			if (i % 2 == 0) {
				binaryTree[i / 2].left = &binaryTree[i];
			}
			else {
				binaryTree[i / 2].right = &binaryTree[i];
			}
		}
	}

	printf("level order: ");
	level_order(&binaryTree[1]);
	printf("\n");

	printf("inorder: ");
	inorder(&binaryTree[1]);
	printf("\n");
	printf("preorder: ");
	preorder(&binaryTree[1]);
	printf("\n");
	printf("postorder: ");
	postorder(&binaryTree[1]);
	printf("\n");

}
