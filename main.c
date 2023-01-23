#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validate(long digits) {
  char str[100];
  int arr1[100];
  int arr2[100];
  sprintf(str, "%ld", digits);
  int lenc = strlen(str);
  int sum = 0;
  if (lenc % 2 == 0) {
      for (int i = 0; i < lenc; ++i) {
          arr1[i] = str[i] - '0';
      }
      for (int i = 0; i < lenc; i+=2) {
          arr1[i]+=arr1[i];
      }
      for (int i = 0; i < lenc; ++i) {
          if (arr1[i] > 9) arr2[i] = arr1[i]-9;
          else arr2[i] = arr1[i];
      }
      for (int i = 0; i < lenc; ++i) {
          sum += arr2[i];
      }
  }
  else if (lenc % 2 != 0) {
      for (int i = 0; i < lenc; ++i) {
          arr1[i] = str[i] - '0';
      }
      for (int i = 1; i < lenc; i+=2) {
          arr1[i]+=arr1[i];
      }
      for (int i = 0; i < lenc; ++i) {
          if (arr1[i] > 9) arr2[i] = arr1[i]-9;
          else arr2[i] = arr1[i];
      }
      for (int i = 0; i < lenc; ++i) {
          sum += arr2[i];
      }
  }
  if (sum % 10 != 0) return false;
  return true;
}
