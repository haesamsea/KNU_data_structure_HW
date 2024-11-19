#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphMat {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphMat;


typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void initMat(GraphMat* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {

    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
}

void insert_vertexMat(GraphMat* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "vertex index error");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void insert_edgeMat(GraphMat* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphMat* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}


void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("[ % d]", i);
        while (p != NULL) {
            printf(" %d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void adj_list_count(GraphType* g) {
    int cnt = 0;
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("[ % d]", i);
        while (p != NULL) {
            cnt++;
            p = p->link;
        }
        printf("%d ", cnt);
        cnt = 0;
        printf("\n");
    }
}

int main()
{
    int inputNum = 0;
    int number1=0, number2 = 0;
    GraphType* g;
    GraphMat* m;
    GraphType* g2;
    g = (GraphType*)malloc(sizeof(GraphType));
    g2 = (GraphType*)malloc(sizeof(GraphType));
    m = (GraphMat*)malloc(sizeof(GraphMat));
    init(g);
    init(g2);
    initMat(m);

    FILE* fp = fopen("in1.txt", "r");
    fscanf(fp, "%d ", &inputNum);
    for (int i = 0; i < inputNum; i++)
    {
        insert_vertex(g, i);
        insert_vertex(g2, i);
        insert_vertexMat(m, i);
    }
  
    while (!feof(fp)) {
        fscanf(fp, "%d %d ", &number1, &number2);
        insert_edge(g, number1, number2);
        insert_edge(g2, number2, number1);
        insert_edgeMat(m, number1, number2);
    }
    printf("(1) Adjacency matrix\n");
    print_adj_mat(m);
    printf("\n(2) Linked adjacency list\n");
    print_adj_list(g);
    printf("\n(3) Inverse adjacency list\n");
    print_adj_list(g2);
    printf("\n(4) In degree\n");
    adj_list_count(g2);
    printf("\n(5)Out degree\n");
    adj_list_count(g);

    free(g);
    free(g2);
    free(m);

    return 0;


}