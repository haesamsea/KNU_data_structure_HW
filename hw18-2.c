#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10

int visited[MAX_VERTICES];

typedef int element;

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;


void init(GraphType* g) {
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


void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex index error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}


void dfs_mat(GraphType* g, int v) {
    int w;
    visited[v] = TRUE;
    printf("  %d", v);
    for (w = 0; w < g->n; w++)
        if (g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w);
}



void error(char* message) {
    fprintf("stderr", message);
    exit(1);
}

void queue_init(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("overflow");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q))
        error("underflow");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

void bfs_mat(GraphType* g, int v) {
    int w;
    QueueType q;

    queue_init(&q);
    visited[v] = TRUE;
    printf("  %d", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = 0; w < g->n; w++)
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;
                printf("  %d", w);
                enqueue(&q, w);
            }
    }
}


int main(void) {
    GraphType* g;
    GraphType* g1;
    int cnt = 0;

    int matrix[20][20];
    int input = 0;

    g = (GraphType*)malloc(sizeof(GraphType));
    g1 = (GraphType*)malloc(sizeof(GraphType));

    FILE* fp = fopen("in.txt", "r");

    fscanf(fp, "%d", &cnt);
    init(g);
    init(g1);

    for (int i = 0; i < cnt; i++) {
        insert_vertex(g, i);
        insert_vertex(g1, i);
    }

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < cnt; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                insert_edge(g, i, j);
                insert_edge(g1, i, j);
            }
        }

    printf("by DFS:\n");

    for (int i = 0; i < 9; i++) {
        if (visited[i] == FALSE) {
            input += 1;
            printf("Component #%d: ", input);
            dfs_mat(g, i);
            printf("\n");
        }
    }

    for (int i = 0; i < MAX_VERTICES; i++)
        visited[i] = FALSE;

    printf("\n");
    input = 0;
    printf("by BFS:\n");
    for (int i = 0; i < 9; i++) {
        if (visited[i] == FALSE) {
            input += 1;
            printf("Component #%d: ", input);
            bfs_mat(g1, i);
            printf("\n");
        }
    }


    free(g);
    free(g1);
    return 0;
}