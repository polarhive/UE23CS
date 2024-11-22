#include <stdio.h>
int search(int *arr, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return 1; // Element found
    }
  }
  return 0; // Element not found
}
int main() {
  int a[10];
  int n, m;
  printf("Enter the size of array:\n");
  scanf("%d", &n);
  printf("Enter the elements: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Enter the element to be searched\n");
  scanf("%d", &m); // Use a different variable for the search element
  int result = search(a, n, m);
  if (result) {
    printf("Element found.\n");
  } else {
    printf("Element not found.\n");
  }
  return 0;
}
