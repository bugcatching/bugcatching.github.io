// 125. Valid Palindrome

#include "utils.c"

int validPalindrome(char *s) {
  int length = strlen(s); // calculate only once
  char *o = (char *)malloc(length + 1);
  if (o == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  stripPunctuation(s, o);

  for (int i = 0; i < strlen(o) / 2; i++) {
    if (o[0 + i] != o[strlen(o) - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
