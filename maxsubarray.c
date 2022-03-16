#include <limits.h>
#include <stdio.h>

typedef struct {
  int left;
  int right;
  int sum;
} SubArray;

SubArray maxMidArray(int *a, int low, int mid, int max) {
  int leftmax = 0;
  int rightmax = 0;

  int leftsum = INT_MIN;
  int rightsum = INT_MIN;

  int sum = 0;

  for (int i = mid; i >= low; i--) {
    sum += a[i];

    if (sum > leftsum) {
      leftsum = sum;

      leftmax = i;
    }
  }

  sum = 0;

  for (int i = mid + 1; i <= max; i++) {
    sum += a[i];

    if (sum > rightsum) {
      rightsum = sum;

      rightmax = i;
    }
  }

  SubArray subarray;
  subarray.left = leftmax;
  subarray.right = rightmax;
  subarray.sum = leftsum + rightsum;

  return subarray;
}

SubArray maxSubArray(int *a, int low, int max) {

  SubArray subarray;
  subarray.left = low;
  subarray.right = max;
  subarray.sum = a[low];

  if (low == max)
    return subarray;
  else {
    int mid = (max + low + 1) / 2 - 1;
    SubArray leftmax = maxSubArray(a, low, mid);

    SubArray rightmax = maxSubArray(a, mid + 1, max);

    SubArray midmax = maxMidArray(a, low, mid, max);

    if (leftmax.sum > rightmax.sum && leftmax.sum > midmax.sum)
      return leftmax;
    else if (rightmax.sum > leftmax.sum && rightmax.sum > midmax.sum)
      return rightmax;
    else
      return midmax;
  }
}

int main() {
  int stock[] = {13, -3, -25, 20, -3,  -16, -23, 18,
                 20, -7, 12,  -5, -22, 15,  -4,  7};
  SubArray submax = maxSubArray(stock, 0, sizeof(stock) / sizeof(int) - 1);
  printf("%i %i %i, %i", stock[submax.left], stock[submax.right], submax.sum,
         INT_MIN);

  return 0;
}
