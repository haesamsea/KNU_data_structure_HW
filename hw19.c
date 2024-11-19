#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;
	int nvertex;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	g->n = g->nvertex = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int w) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return(x->weight - y->weight);
}

void kruskal(GraphType* g) {
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(g->nvertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("(edge): weight\n");
	int i = 0;
	while (edge_accepted < (g->nvertex - 1)) {
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("(%d %d): %d\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}

int main(void) {

	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	
	int matrix[20][20];
	int input = 0, cnt = 0;

	FILE* fp = fopen("in.txt", "r");

	fscanf(fp, "%d", &input);
	while (!feof(fp)) {
		for(int i = 0;i < input ;i++){
			for (int j = 0; j < input; j++) {
				fscanf(fp, "%d ", &matrix[i][j]);
				if (matrix[i][j] != 0) cnt++;
			}
		}
	}

	graph_init(g);
	cnt /= 2;
	g->nvertex = cnt;

	for (int i = 0; i < input; i++) {
		for (int j = i; j < input; j++) {
			if (matrix[i][j]!=0){
				insert_edge(g, i, j, matrix[i][j]);
			}
		}
	}

	kruskal(g);
	free(g);

	return 0;
}