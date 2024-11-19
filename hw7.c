#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc함수를 이용하기 위한 헤더 파일
#define MAX_STACK_SIZE 100

int number = 0;

typedef int element;
typedef struct {
	element *data; //포인터로 정의 (int*data)
	int capacity; //내용물 양
	int top; //스택의 맨 윗칸
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		printf("doubling %d ", s->capacity);
	}
	s->data[++(s->top)] = item;
}

element pop(StackType*s)
{
	if (is_empty(s)) {
		fprintf(stderr, "stack is empty: cannot pop");
		//exit(1);
	}
	else
	{
		if (s->capacity <= 1)
			printf("stack is empty");
		if (s->capacity >= 2){
			s->capacity = s->capacity / 2;
			s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
			printf("reducing size(/2): %d",s->capacity);
		}
		s->data[(s->top)--];
	}
}

element peek(StackType *s) {
	for (int i = 0; i < number; i++) {
		printf("[ %d]", s->data[i]);
	}
}

int main() {
	
	FILE* fp = fopen("in.txt", "r");
	StackType s;
	int arr[100], i = 0;

	init_stack(&s);

	while (!feof(fp)) {
		fscanf(fp, "%d ", &arr[i++]);
	}

	for (int j = 0; j < i; j++)
		printf("%d ", arr[j]);
	
	printf("\n");

	for (int j = 0; j < i; j++) 
	{
		if (arr[j] != -1)
		{
			printf("push item: %d ==>", arr[j]);
			number++;
			push(&s, arr[j]);
			peek(&s);
		}
		else
		{
			printf("pop => ");
			if (number>0)
				number--;
			pop(&s);
			peek(&s);
		}
	printf("\n");
	} 

	printf("\n\n최종 stack 출력\n");

	for (int i = number-1; i >= 0; i--) {
		printf("< %3d>\n", s.data[i]);
	}
}