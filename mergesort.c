#include <limits.h>
#include <stdio.h>

void merge(int *a, int p, int q, int r) {
  int leftn = q - p + 1;
  int rightn = r - (q + 1) + 1;

  int left[leftn];
  int right[rightn];

  for (int i = 0; i < leftn; i++) {
    left[i] = a[p + i];
  }

  for (int i = 0; i < rightn; i++) {
    right[i] = a[q + i + 1];
  }

  int j = 0;
  int i = 0;
  for (int k = p; k <= r; k++) {
    if (left[j] >= right[i]) {
      a[k] = right[i];

      i++;
      if (i >= rightn)
        right[i] = INT_MAX;
    } else {
      a[k] = left[j];

      j++;

      if (j >= leftn)
        left[j] = INT_MAX;
    }

    // printf("|%i %i|", j, i);

    // printf("%i", a[k]);
  }
}

void mergesort(int *a, int p, int r) {
  if (p < r) {
    int q = ((p + r + 1) / 2) - 1;

    mergesort(a, p, q);
    mergesort(a, q + 1, r);

    merge(a, p, q, r);
  }
}

int main() {

  int numbers[] = {5, 2, 4, 7, 1, 3, 2, 6};

  mergesort(numbers, 0, sizeof(numbers) / sizeof(int) - 1);
  printf("\n");
  for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
    printf("%i,", numbers[i]);
  }
  return 0;
}
