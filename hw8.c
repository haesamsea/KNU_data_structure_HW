#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100 /* max size of expression */
#define EOS 0

int stack[MAX_STACK_SIZE]; /* global stack */
char expr[MAX_EXPR_SIZE]; /* input string */
char exprt[MAX_EXPR_SIZE];

int top = -1;

int pop() {
    if (top < 0) {
        return top;
    }
    return stack[top--];
}

char push(char token) {
    if (MAX_STACK_SIZE - 1 == top) {
        printf("stack full");
        return 0;
    }
    stack[++top] = token;
}

int getPriority(char token)
{
    switch (token) {
    case '(': return 20;
    case ')': return 19;
    case '+': return 12;
    case '-': return 12;
    case '/': return 13;
    case '*': return 13;
    case '%': return 13;
    }
}

int getinStackPriority(char token)
{
    switch (token) {
    case '(': return 0;
    case ')': return 19;
    case '+': return 12;
    case '-': return 12;
    case '/': return 13;
    case '*': return 13;
    case '%': return 13;
    }
}

int isDigit(char token) {
    if ('0' <= token && token <= '9') {
        return 1;
    }
    else {
        return 0;
    }
}

void postfix(char* expr, char* exprt)
{
    char token;
    int cnt = 0;
    push(EOS);
    for (int i = 0; expr[i] != 0; i++)
    {
        if (expr[i] == '\n') {
            break;
        }
        token = expr[i];
        if (isDigit(token))
            exprt[cnt++] = token;
        else {
            if (token == ')') {
                do {
                    exprt[cnt++] = pop();
                } while (exprt[cnt - 1] != '(');
                cnt--;
                continue;
            }
            while (getinStackPriority(stack[top]) >= getPriority(token)) {
                exprt[cnt++] = pop();
            }
            push(token);
        }
    }
    do {
        exprt[cnt++] = pop();
    } while (exprt[cnt - 1] != EOS);
}

int eval(char* exprt) {
    char token, op1, op2;
    for (int i = 0; exprt[i] != 0; i++) {
        if (exprt[i] == '\n') {
            break;
        }
        token = exprt[i];
        if (isDigit(token) == 1) {
            push(token - '0');
        }
        else {
            op1 = pop(), op2 = pop();
            switch (token) {
            case '+':
                push(op2 + op1); break;
            case '-':
                push(op2 - op1); break;
            case '*':
                push(op2 * op1); break;
            case '/':
                push(op2 / op1); break;
            case '%':
                push(op2 % op1); break;
            }
        }
    }
    return pop();
}

int main(void) {
    FILE* fp = fopen("infix.txt", "r");
    int n = 0;

    while (!feof(fp)) {
        int count = 0;
        fgets(expr, sizeof(expr), fp);
        n++;
        postfix(expr, exprt);
        if (n == 4) {
            printf("Infix: %s", expr);
        }
        else {
            printf("Infix: %s", expr);
        }
        printf("Postfix:%s\n", exprt);
        printf("Result:%d\n\n", eval(exprt));
    }
    fclose(fp);
}