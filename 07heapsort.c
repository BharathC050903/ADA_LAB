#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int arr[], int n, int i)
{
  int largest = i;       // Initialize largest as root
  int left = 2 * i + 1;  // left = 2*i + 1
  int right = 2 * i + 2; // right = 2*i + 2

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n)
{

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--)
  {

    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
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

  heapsort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
