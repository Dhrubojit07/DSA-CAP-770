#include <iostream>
#include <stack>

// Function to swap two elements
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// Partition function to rearrange elements around a pivot
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1); // Index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // Check if current element is less than the pivot
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// Recursive quicksort function using a stack
void quickSort(int arr[], int low, int high) {
  std::stack<std::pair<int, int>> s;

  // Push the initial low and high indices onto the stack
  s.push(std::make_pair(low, high));

  // Pop elements from the stack and perform partition until empty
  while (!s.empty()) {
    std::pair<int, int> p = s.top();
    s.pop();

    low = p.first;
    high = p.second;

    // Partition the array
    int pi = partition(arr, low, high);

    // Push the right subarray onto the stack if it has at least two elements
    if (pi - low >= 1) {
      s.push(std::make_pair(pi + 1, high));
    }

    // Push the left subarray onto the stack if it has at least two elements
    if (high - pi >= 1) {
      s.push(std::make_pair(low, pi - 1));
    }
  }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Unsorted array: ";
  printArray(arr, n);

  quickSort(arr, 0, n - 1);

  std::cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
