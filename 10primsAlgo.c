#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int V)
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V)
{
  int totalWeight = 0;
  printf("Edge \tWeight\n");
  for (int i = 1; i < V; i++)
  {
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    totalWeight += graph[i][parent[i]];
  }
  printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[MAX][MAX], int V)
{
  int parent[MAX];
  int key[MAX];
  bool mstSet[MAX];

  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++)
  {

    int u = minKey(key, mstSet, V);

    mstSet[u] = true;

    for (int v = 0; v < V; v++)

      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }

  printMST(parent, graph, V);
}

int main()
{
  int V;
  int graph[MAX][MAX];

  printf("Enter the number of vertices: ");
  scanf("%d", &V);

  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  primMST(graph, V);

  return 0;
}
