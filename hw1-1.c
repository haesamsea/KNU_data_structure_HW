#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
    char number[5];
    char name[5];
    char phone[20];
    int age;
};

typedef struct student Stu;

int main() {
    int number = 0; // 총 학생 수
    int age = 0;    // 기준 나이
    FILE* fp = fopen("score.txt", "r");
    FILE* fp2 = fopen("result.txt", "w");

    if (fp == NULL || fp2 == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    fscanf(fp, "%d", &number);

    // 동적 할당
    Stu* input = (Stu*)malloc(sizeof(Stu) * number);
    if (input == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        fclose(fp);
        fclose(fp2);
        return 1;
    }

    // 파일로부터 데이터 읽기
    for (int i = 0; i < number; i++) {
        fscanf(fp, "%s %s %s %d", input[i].number, input[i].name, input[i].phone, &input[i].age);
    }

    // 나이 입력받기
    printf("기준 나이를 입력하세요: ");
    scanf("%d", &age);

    // 기준 나이 이상인 데이터를 result.txt에 쓰기
    for (int i = 0; i < number; i++) {
        if (input[i].age >= age) {
            fprintf(fp2, "%s, %s, %s, %d\n", input[i].number, input[i].name, input[i].phone, input[i].age);
        }
    }

    // 동적 메모리 해제 및 파일 닫기
    free(input);
    fclose(fp);
    fclose(fp2);

    printf("작업이 완료되었습니다.\n");
    return 0;
}
