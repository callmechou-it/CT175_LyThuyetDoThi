#include <stdio.h>
#define MAX_N 100
#define MAX_SIZE 100
int mark[MAX_N];

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for(int u = 1; u <= n; u++)
        for(int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}
void add_edge(Graph *pG, int u, int v){
    pG->A[u][v] = 1;
    pG->A[v][u] = 1;
    pG->m++;
}
int adjacent(Graph *pG, int u, int v){
    return pG->A[u][v] > 0;
}

typedef int ElementType;
typedef struct {
	ElementType data[MAX_SIZE];
	int front, rear;
} Queue;

void make_null_queue(Queue *pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

void enqueue(Queue *pQ, ElementType u) {
	pQ->rear++;
	pQ->data[pQ->rear] = u;
}

ElementType front(Queue *pQ) {
	return pQ->data[pQ->front];
}

void dequeue(Queue *pQ) {
	pQ->front++;
}

int empty(Queue *pQ) {
	return pQ->front > pQ->rear;
}

void BFS(Graph *pG, int s) {
	Queue Q;
	make_null_queue(&Q);
	enqueue(&Q, s);
	while(!empty(&Q)) {
		int u = front(&Q);
		dequeue(&Q);
		if(mark[u] != 0)
			continue;
		printf("%d\n", u);
		mark[u] = 1;
		for(int v = 1; v <= pG->n; v++)
			if(adjacent(pG, u, v))
				enqueue(&Q, v);
	}
}

int main(){
	Graph G;
	int n, m, u, v, i;
	scanf("%d %d", &n, &m);
	init_graph(&G, n);
	for(i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(i = 1; i <= G.n; i++)
		mark[i] = 0;
		
	BFS(&G, 1);
	for(i = 1; i <= G.n; i++)
		BFS(&G, i);
	return 0;
}

