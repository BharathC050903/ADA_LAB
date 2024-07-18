#include <stdio.h>

#define MAX_SIZE 1000  // Define a maximum size for the array

int arr[MAX_SIZE];
int L[MAX_SIZE / 2 + 1];
int R[MAX_SIZE / 2 + 1];

// Function to merge two subarrays
void merge(int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to implement merge sort
void mergeSort(int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
  }
}

int main()
{
  int numTests;

  printf("Enter the number of test cases: ");
  scanf("%d", &numTests);

  for (int t = 0; t < numTests; t++)
  {
    int N;
    printf("\nEnter the number of elements for test case %d: ", t + 1);
    scanf("%d", &N);

    printf("Enter the elements:\n");
    for (int i = 0; i < N; i++)
    {
      scanf("%d", &arr[i]);
    }

    mergeSort(0, N - 1);

    printf("Sorted array for test case %d:\n", t + 1);
    for (int i = 0; i < N; i++)
    {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  return 0;
}
