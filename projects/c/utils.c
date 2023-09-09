#include <ctype.h>
#include <string.h>

#define DEBUG 1
#define DEBUG_PRINT(fmt, ...)                                                  \
  \ 
    do {                                                                       \
    if (DEBUG)                                                                 \
      fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__,                  \
              __func__ __VA_OPT__(, ) __VA_ARGS__);                            \
  }                                                                            \
  while (0)

#define SWAP(x, y, T)                                                          \
  do {                                                                         \
    T tmp = (*x);                                                              \
    (*x) = (*y);                                                               \
    (*y) = tmp;                                                                \
  } while (0)

#define NUM_ELEMS(x) ((sizeof(x)) / (sizeof((x)[0])))

#define MAX_Q_SIZE 500

inline void inlineSwap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}


void stripPunctuation(char *s, char *o) {
  int j = 0;

  for (int i = 0; i < strlen(s); i++) {
    if (!ispunct(s[i]) && !isspace(s[i])) {
      o[j] = tolower(s[i]);
      j++;
    }
  }

  o[j] = '\0';
}

void heapify(int arr[], int N, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < N && arr[left] > arr[largest])

    largest = left;

  if (right < N && arr[right] > arr[largest])

    largest = right;

  if (largest != i) {

    SWAP(&arr[i], &arr[largest], int);
    heapify(arr, N, largest);
  }
}

void heapSort(int arr[], int N) {
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);

  for (int i = N - 1; i >= 0; i--) {
    SWAP(&arr[0], &arr[i], int);
    heapify(arr, i, 0);
  }
}
