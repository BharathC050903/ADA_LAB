#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  while (i <= j)
  {
    while (i <= j && arr[i] <= pivot)
    {
      i++;
    }
    while (i <= j && arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);

  return j;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Unsorted array: \n");
  printArray(arr, n);

  quicksort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
