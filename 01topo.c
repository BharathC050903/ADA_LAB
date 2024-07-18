#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int adj[MAX][MAX];
int vertices;

int topologicalSorting(int v)
{
  int i, j, k;
  int topologicalOrder[v];
  int temp = 0;
  int visited[v];

  for (i = 0; i < v; i++)
  {
    topologicalOrder[i] = -1;
    visited[i] = 0;
  }

  while (temp < v)
  {
    for (j = 0; j < v; j++)

    {
      if (visited[j])
      {
        continue;
      }

      int flag = 1;

      for (i = 0; i < v; i++)
      {
        if (adj[i][j] == 1)
        {
          flag = 0;
          break;
        }
      }

      if (flag)
      {
        topologicalOrder[temp++] = j;
        visited[j] = 1;

        for (k = 0; k < v; k++)
        {
          adj[j][k] = 0;
        }
      }
    }
    if (temp != j)
    {
      printf("Cycle exists\n");
      return 0;
    }
  }

  printf("Topological Order: ");
  for (i = 0; i < temp; i++)
  {
    if (topologicalOrder[i] != -1)
    {
      printf("%d ", topologicalOrder[i]);
    }
  }
  printf("\n");
  return 1;
}

int main()
{
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  if (vertices > MAX)
  {
    printf("Number of vertices exceeds the maximum limit of %d.\n", MAX);
    return 1;
  }

  printf("Enter adjacency matrix (1 if edge exists, 0 otherwise):\n");
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      scanf("%d", &adj[i][j]);
    }
  }

  topologicalSorting(vertices);

  return 0;
}
