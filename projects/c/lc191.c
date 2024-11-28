// 191. Number of 1 Bits

int hammingWeight(u_int32_t n) {
  int count = 0;
  while (n > 0) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}
