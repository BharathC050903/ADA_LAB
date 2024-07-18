#include <stdio.h>

#define INF 99999
#define MAX 10

int distance[MAX][MAX]; // Globally declare distance matrix

void floydWarshall(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        distance[i][j] = 0;
      else if (distance[i][j] == 0)
        distance[i][j] = INF;
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (distance[i][k] < INF && distance[k][j] < INF && distance[i][j] > distance[i][k] + distance[k][j])
        {
          distance[i][j] = distance[i][k] + distance[k][j];
        }
      }
    }
  }
}

void printMatrix(int n)
{
  printf("The shortest distances between every pair of vertices:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (distance[i][j] == INF)
        printf("%7s", "INF");
      else
        printf("%7d", distance[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &distance[i][j]);
    }
  }

  floydWarshall(n);

  printMatrix(n);

  return 0;
}
