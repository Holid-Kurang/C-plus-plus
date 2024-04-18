#include<iostream>
#include <stdio.h>
using namespace std;

double calculateAverage(int arr[], int size) {
  double sum = 0;
  for(int i = 0; i < size; i++) {
    sum += arr[i];
  }
  double average = sum / size;
  return average;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = 5;
  double avg = calculateAverage(arr, size);
  printf("Average: %f", avg);
  return 0;
}

