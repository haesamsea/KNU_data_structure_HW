#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}NODE;


void insert_node(NODE** head, int n); // 삽입함수
void search_node(NODE* head, int n); // 검색함수
void print_node(NODE* head); // 출력함수
void delete_node(int n); // 삭제함수
int flag = 0, locate = 0; // 검색 시 해당 숫자 존재유무 및 위치저장변수


NODE* head = NULL;
//NODE* head2 = NULL;

main()
{
	int i = 0;

	FILE* fp = fopen("in3.txt", "r");
	puts("original");
	while (!feof(fp)) {
		fscanf(fp, "%d ", &i);
		insert_node(&head, i);
		//mainList->link = appendNode(mainLisk* link, mainList.data);
		printf("%d ", i);
	}
	puts("");
	i = 0;

	fclose(fp);
	
	FILE* fp2 = fopen("in4.txt", "r");
	puts("original");
	while (!feof(fp2)) {//printf("%d,,\n", head);
		fscanf(fp2, "%d ", &i);
		if (i % 2 == 0)// 짝수일 때 insert
		{
			insert_node(&head, i);
			printf("insert %d ==> ", i);
		}
		else
		{
			search_node(head ,i);
			if (flag != 1) printf("없음 ");
			else {
				delete_node(i);
				printf("delete %d ==> ", i);
			}
		}
		
		print_node(head);
		
	}
	
 while (head == NULL){
		free(head);
	 }

	fclose(fp2);
	i = 0;
	
	 head = NULL;
	
	printf("===============================\n");
	FILE* fp3 = fopen("in3.txt", "r");
	puts("original");
	while (!feof(fp3)) {
		fscanf(fp3, "%d ", &i);
		insert_node(&head, i);
		//mainList->link = appendNode(mainLisk* link, mainList.data);
		printf("%d ", i);
	}
	puts("");
//	i = 0;

	fclose(fp3);

	FILE* fp4 = fopen("in5.txt", "r");
	
	//puts("original");
	while (!feof(fp4)) {
		//printf("%d,,\n", head);
		fscanf(fp4, "%d ", &i);
		if (i % 2 == 0)// 짝수일 때 insert
		{
			insert_node(&head, i);
			printf("insert %d ==> ", i);
		}
		else 
		{
			search_node(head,i);
			if (flag != 1) printf("delete %d ==> %d 없음 ",i,i);
			else {
				delete_node(i);
				printf("delete %d ==> ", i);
			}
		}
		
		print_node(head);
	}
	fclose(fp4);
}

void print_node(NODE* head)
{
	NODE* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}



void search_node(NODE* head, int n)
{
	flag = 0;
	locate = 0;
	NODE* p = head;

	while (p != NULL) {
	locate++;
		if (p->data == n) {
			flag = 1;
			break;
		}
		else
			p = p->link;
	
	}
}



void insert_node(NODE** head, int n) // 삽입 시 오름차순으로 정렬하여 삽입하는 함수
{

	NODE* p = *head;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->data = n;
	node->link = NULL;

	if (*head == NULL) // 헤드가 비었을때, 즉 빈리스트 일때
	{
		*head = node;
	}
	else if (p->data > node->data) // 빈리스트는 아니지만 헤드의 앞에 삽입하고 싶을때
	{
		node->link = p;
		*head = node;
	}
	else // 빈리스트도 아니고 헤드의 앞에 삽입도 아닐 때
	{
		while (p->link != NULL && p->link->data < node->data)
			p = p->link;
		node->link = p->link;
		p->link = node;
	}
}


void delete_node( int n) // 삭제함수
{
	
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	NODE* p = head;

	if (head == NULL) // head가 비어있을경우
	{
		puts("빈 리스트입니다.");
		return;
	}

	if (head->data == n)//삭제할 위치가 맨앞이라면
	{
		temp = head;//삭제할 위치 저장
		head = head->link;//맨앞위치를 다음으로 변경
		free(temp);//메모리 삭제

		return;

	}

	while (p->link != NULL)

	{ // NULL 이 아닐때까지

		if (p->link->data == n)

		{

			temp = p->link; // 삭제할 위치 저장

			p->link = p->link->link; // 삭제할 위치를 건너뛰어 연결

			free(temp); // 메모리 삭제

			return;

		}

		p = p->link; // 다음 노드로 이동

	}

}
