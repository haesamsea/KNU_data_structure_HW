#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
   int data;
   struct NODE* lchild, * rchild;
};
typedef struct NODE NODE;
typedef NODE* LINK;

void inorder(LINK ptr) {
   if (ptr) {
      inorder(ptr->lchild);
      printf("%d ", ptr->data);
      inorder(ptr->rchild);
   }
}

LINK makeTree(int n) {
   LINK head = NULL;
   if (n > 1000) return head;
   
   head = (NODE*)malloc(sizeof(NODE));
   head->lchild = makeTree(n * n);
   head->data = n;
   head->rchild = makeTree(n * 5);
   return head;
}

int main() {
   int n;
   LINK head;
   printf("Input number:");
   scanf("%d", &n);
   head = makeTree(n);
   inorder(head);
   
   return 0;
}