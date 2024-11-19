#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//serachBST함수:root에서 x의 값을 찾아서 그 위치를 반환하기때문에 treeNode*를 반환한다
treeNode* searchBST(treeNode* root, int x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right; //x>p->key 인 경우
	}
	return;
}


treeNode* insertNode(treeNode* p, int x) {
	treeNode* newNode;

	if (p == NULL) { //p가 첫번째로 온 경우
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("[ 넣을려는 값과 같은 값이 이미 있습니다 ]\n");

	return p;
}



void displayPostorder(treeNode* root) {
	if (root) {
		displayPostorder(root->left);
		displayPostorder(root->right);
		printf("%d ", root->key);
	}
}

int main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	int N[30] = { NULL };
	int choice;
	int key;
	int t = 1;

	FILE* fp = fopen("in1.txt", "r");

	fscanf(fp, "%d ", &N[0]);
	root = insertNode(root, N[0]);

	while (!feof(fp)) {
		fscanf(fp, "%d ", &N[t]);
		insertNode(root, N[t]);
		t++;
	}


	printf("Postorder traversal:\n");
	displayPostorder(root);

	while (1) {
		printf("\nInput number: ");
		scanf_s("%d", &key);
		getchar();

		if (key >= 0) {
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("  %d : O  ", foundedNode->key);
			else
				printf("  %d : X  ", key);
		}
		else {
			printf("Quit.");
			break;
		}
	}
}