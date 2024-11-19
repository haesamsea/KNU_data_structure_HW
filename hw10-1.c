#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct node {// 노드 구조체 선언
	struct node* next;//다음 주소
	int data; // 정보
}node;

void addset(node* set, int elem) {// 집합set에 원소elem 추가
	node* newnode = (node*)malloc(sizeof(node));// 새로운 노드 할당
	newnode->data = elem;
	newnode->next = NULL;// 초기화 해주고

	while (set->next != NULL) {//집합 끝에 노드추가
		set = set->next;
	}
	set->next = newnode;
}



node* intersect(node* A, node* B) {// 이거는 교집합
	node* first = A;
	node* second = B;
	node* intersect = (node*)malloc(sizeof(node));// 교집합 담을 리스트

	intersect->data = NULL;
	intersect->next = NULL;

	if ((first->next == NULL) && (second->next == NULL)) {//둘 다 공집합이면
		//printf("공통된 원소가 없음");
		return;// 걍 빈 리스트 반환
	}
	else if (first->next == NULL) {// 첫번째만 공집합이어도
		printf("공통된 원소가 없음");
		return ;// 빈리스트 반환 왜냐믄 교집합이니께
	}
	else if (second->next == NULL) {// 어 얘도 똑같이
		//printf("공통된 원소가 없음");
		return ;
	}
	else {// 둘다 공집합이 아니야
		first = first->next;
		second = second->next;

		while ((first != NULL) && (second != NULL)) {// 둘 중 하나가 끝나면 끝나는 반복문이여
			if (first->data == second->data) {//원소가 같으면
				addset(intersect, first->data);// 둘 중 하나만 추가해
				first = first->next;
				second = second->next;
			}
			else if (first->data < second->data)// 원소가 다르면 적은것부터 순서대로 추가
				first = first->next;
			else if (first->data > second->data)
				second = second->next;
		}
	}

	 return intersect;

}

void print(node* set) {// 출력
	node* p = set->next;// 임시로 노드 하나 선언하고 집합 연결
	if (p == NULL)
		printf("공통된 원소가 없음\n");// 그게 근데 빈집합이야 공집합, 그러면 0 반환
	else {
		while (p != NULL) {// 끝까지
			printf(" %d", p->data);// 집합 원소 출력~!
			p = p->next;
		}
		printf("\n");
	}
}

void freeset(node* set) {// 메모리 해제
	node* p = set;
	while (p != NULL) {
		set = set->next;
		free(p);
		p = set;
	}
}

int main() {
	int size, elem;
	node* A = (node*)malloc(sizeof(node));
	node* B = (node*)malloc(sizeof(node));// 집합 할당 먼저해주고
	node* sumset, * intersectset;//얘들은 각각 합집합 교집합 받을 것들
	A->data = NULL;
	A->next = NULL;
	B->data = NULL;
	B->next = NULL;// 초기화 해주기

	
	FILE* fp = fopen("in1.txt", "r");
	printf("[in1.txt]\n");

	while (!feof(fp)) {
		fscanf(fp, "%d ", &elem);
		addset(A, elem);// A집합 원소 받아서 집합에 넣기
		printf("%d ", elem);
	}
	fclose(fp);

	printf("\n");

	FILE* fp2 = fopen("in2.txt", "r");
	printf("[in2.txt]\n");

	while (!feof(fp2)) {
		fscanf(fp2, "%d ", &elem);
		addset(B, elem);// A집합 원소 받아서 집합에 넣기
		printf("%d ", elem);
	}
	printf("\n");
	printf("[in1 AND in2]\n");
	
	intersectset = intersect(A, B);// 교집합 구하기
	print(intersectset);// 출력
	
	free(A);
	free(B);// 메모리 해제
	
	free(intersectset);

}