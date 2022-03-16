#include <math.h>
#include <stdio.h>

void MaxHeapfy(int *A, int i, size_t size) {
  // last -1 if for the indexes
  int left = 2 * (i + 1) - 1;
  int right = 2 * (i + 1) + 1 - 1;

  int biggest;

  if (right <= size && A[left] > A[i])
    biggest = left;
  else
    biggest = i;

  if (right <= size && A[right] > A[biggest])
    biggest = right;

  if (i != biggest) {
    int temp = A[i];
    A[i] = A[biggest];
    A[biggest] = temp;

    MaxHeapfy(A, biggest, size);
  }
}

void printHeap(int *A, size_t size) {

  int height = ceil(log2(size));

  for (int h = 1; h <= height; h++) {
    int heightLength = pow(2, h - 1);

    for (int node = heightLength - 1; node < (heightLength * 2 - 1); node++) {
      printf("%i   ", A[node]);
    }
    printf("\n");
    for (int node = heightLength - 1; node < (heightLength * 2 - 1); node++) {
      printf("/ \\  ");
    }
    printf("\n");
  }
}

int main() {

  int list[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  printHeap(list, sizeof(list) / sizeof(int));
  MaxHeapfy(list, 1, sizeof(list) / sizeof(int));
  printf("\n\n");
  printHeap(list, sizeof(list) / sizeof(int));
  return 0;
}
