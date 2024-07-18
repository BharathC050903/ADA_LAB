#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

struct Edge
{
  int src, dest, weight;
};

struct Graph
{
  int V, E;
  struct Edge *edge;
};

struct subset
{
  int parent;
  int rank;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void KruskalMST(struct Graph *graph);

struct Graph *createGraph(int V, int E)
{
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
  return graph;
}

int find(struct subset subsets[], int i)
{
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
  int rootX = find(subsets, x);
  int rootY = find(subsets, y);

  if (subsets[rootX].rank < subsets[rootY].rank)
    subsets[rootX].parent = rootY;
  else if (subsets[rootX].rank > subsets[rootY].rank)
    subsets[rootY].parent = rootX;
  else
  {
    subsets[rootY].parent = rootX;
    subsets[rootX].rank++;
  }
}

int compareEdges(const void *a, const void *b)
{
  struct Edge *edgeA = (struct Edge *)a;
  struct Edge *edgeB = (struct Edge *)b;
  return edgeA->weight - edgeB->weight;
}

void KruskalMST(struct Graph *graph)
{
  int V = graph->V;
  struct Edge result[MAX];
  int e = 0;
  int i = 0;

  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

  struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

  for (int v = 0; v < V; v++)
  {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while (e < V - 1 && i < graph->E)
  {

    struct Edge next_edge = graph->edge[i++];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y)
    {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  int totalWeight = 0;
  printf("Edge \tWeight\n");
  for (i = 0; i < e; i++)
  {
    printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
    totalWeight += result[i].weight;
  }
  printf("Total weight of MST: %d\n", totalWeight);

  free(subsets);
}

int main()
{
  int V;
  printf("Enter the number of vertices: ");
  scanf("%d", &V);

  int graph[MAX][MAX];
  printf("Enter the adjacency matrix (enter 99999 for no edge):\n");
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  int E = 0;
  for (int i = 0; i < V; i++)
  {
    for (int j = i + 1; j < V; j++)
    {
      if (graph[i][j] != INF)
      {
        E++;
      }
    }
  }

  struct Graph *g = createGraph(V, E);

  int k = 0;
  for (int i = 0; i < V; i++)
  {
    for (int j = i + 1; j < V; j++)
    {
      if (graph[i][j] != INF)
      {
        g->edge[k].src = i;
        g->edge[k].dest = j;
        g->edge[k].weight = graph[i][j];
        k++;
      }
    }
  }

  KruskalMST(g);

  free(g->edge);
  free(g);

  return 0;
}
