// 268. Missing Number

int missingNumber(int *nums, int numsSize) {
  int sum = 0;
  int range = 0;
  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    range += i;
  }
  range += numsSize;
  return range - sum;
}
