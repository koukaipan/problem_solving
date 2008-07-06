/* Minimal Spanning Tree */
#include <stdio.h>
#include <math.h>

#define MAXINT		2147483647
#define MAXV		101
#define MAXDEGREE	101

typedef struct{
	int v;
	double weight;
}edge;

typedef struct{
	edge edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int n_vertices;
	int n_edges;
}graph;

void MST_prim(graph* g, int start)
{
	int i;
	bool in_tree[MAXV];
	double distance[MAXV];
	int parent[MAXV];
	int v, w;
	double weight;
	double dist;

	for(i=0; i<g->n_vertices; i++)
	{
		in_tree[i] = false;
		distance[i] = MAXINT;
		parent[i] = -1;
	}
	distance[start] = 0;
	v = start;
	
	while(in_tree[v]==false)
	{
		in_tree[v] = true;

		for(i=0; i<g->degree[v]; i++)
		{
			w = g->edges[v][i].v;
			weight = g->edges[v][i].weight;
			if(distance[w]>weight && in_tree[w]==false)
			{
				distance[w] = weight;
				parent[w] = v;
			}
		}
		v = 0;
		dist = MAXINT;
		for(i=1; i<g->n_vertices; i++)
		{
			if(in_tree[i]==false && dist>distance[i])
			{
				dist = distance[i];
				v = i;
			}
		}
	}

	for(i=0, dist=0.0; i<g->n_vertices; i++)
		dist += distance[i];
	printf("%.2lf\n", dist);
}

int main()
{
	int i, j, n, num_case, flag=0;
	double coord[MAXV][2];	
	graph g;

	freopen("10034.txt", "r", stdin);
	
	for(scanf("%d", &num_case); num_case; num_case--)
	{
		scanf("%d", &n);
		
		for(i=0; i<n; i++)
			scanf("%lf %lf", &coord[i][0], &coord[i][1]);
		
		/* initialize */
		g.n_vertices = n;
		g.n_edges = 0;
		for(i=0; i<n; i++)
			g.degree[i] = 0;

		for(i=0; i<n; i++)
		{
			for(j=0; j<i; j++)
			{
				g.n_edges++;
				g.degree[i]++;
				g.degree[j]++;
				g.edges[i][g.degree[i]-1].v = j;
				g.edges[j][g.degree[j]-1].v = i;
				g.edges[i][g.degree[i]-1].weight = g.edges[j][g.degree[j]-1].weight = 
					sqrt((coord[i][0]-coord[j][0])*(coord[i][0]-coord[j][0])+(coord[i][1]-coord[j][1])*(coord[i][1]-coord[j][1]));
			}
		}
		
		if(flag==true)
			printf("\n");
		else
			flag = true;
		MST_prim(&g, 0);
		
	}/* end of for*/

	return 0;
}

