// 2141. Maximum Running Time of N Computers

#include "utils.c"

long long maxRunTime(int n, int *batteries, int batteriesSize) {
  heapSort(batteries, batteriesSize);
  long long sum = 0;
  for (int i = 0; i < batteriesSize; i++)
    sum += batteries[i];
  int k = 0;
  // only evaluates when there's more battery power in the biggest battery than
  while (batteries[batteriesSize - 1 - k] > sum / (n - k)) {
    sum -= batteries[batteriesSize - 1 - k++];
  }
  return sum / (n - k);
}
