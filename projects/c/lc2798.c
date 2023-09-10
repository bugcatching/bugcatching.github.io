// 2798. Number of Employees Who Met the Target

#include "utils.c"

int numberOfEmployeesWhoMetTarget(int *hours, int hoursSize, int target) {
  heapSort(hours, hoursSize);
  for (int i = 0; i < hoursSize; i++) {
    if (hours[i] >= target) {
      return hoursSize - i;
    }
  }
  return 0;
}
