/* topological sort 
   topsort
   be careful of m=0 */
#include <stdio.h>

#define MAXINT		2147483647
#define MAXV		10
#define MAXDEGREE	10

typedef struct{
	int edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int indegree[MAXV+1];
	int n_vertices;
	int n_edges;
}graph;

typedef struct{
	int front;
	int rear;
	int q[MAXV];
}queue;

void init_queue(queue *q);
void enqueue(queue *q, int v);
int dequeue(queue *q);
int empty(queue *q);
void topsort(graph *g, int sorted[]);

main()
{
	int i, a, b;
	int sorted[MAXV+1];
	graph g;
	freopen("10305.txt", "r", stdin);
	while(scanf("%d %d", &g.n_vertices, &g.n_edges) && (g.n_vertices || g.n_edges))
	{
		for(i=0; i<=g.n_vertices; i++)
			g.indegree[i] = g.degree[i] = 0;
		for(i=0; i<g.n_edges; i++)
		{
			scanf("%d %d", &a, &b);
			g.edges[a][g.degree[a]] = b;
			g.degree[a]++;
			g.indegree[b]++;
		}
		topsort(&g, sorted);
		for(i=0; i<g.n_vertices-1; i++)
			printf("%d ", sorted[i]);
		printf("%d\n", sorted[i]);
	}
}

void topsort(graph *g, int sorted[])
{
	queue zeroin;
	int x, y;
	int i, j;

	init_queue(&zeroin);

	for(i=1; i<=g->n_vertices; i++)
		if(g->indegree[i] == 0)
			enqueue(&zeroin, i);
	j=0;
	while(!empty(&zeroin))
	{
		x = dequeue(&zeroin);
		sorted[j++] = x;
		for(i=0; i<g->degree[x]; i++)
		{
			y = g->edges[x][i];
			g->indegree[y] -= 1;
			if(g->indegree[y] == 0)
				enqueue(&zeroin, y);
		}
	}
}

void init_queue(queue *q)
{
	q->front = q->rear = 0;
}
void enqueue(queue *q, int v)
{
	q->q[q->front] = v;
	q->front = (q->front + 1) % MAXV;
}
int dequeue(queue *q)
{
	int tmp = q->q[q->rear];
	q->rear = (q->rear + 1) % MAXV;
	return tmp;
}
int empty(queue *q)
{
	return q->front == q->rear;
}
