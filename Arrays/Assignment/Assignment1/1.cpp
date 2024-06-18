#include <iostream>
using namespace std;

// Function to calculate the product of all elements in an array
long long calculateProduct(int arr[], int size)
{
  long long product = 1; // Initialize product to 1, since multiplying by 0 would always result in 0

  // Iterate through the array and multiply each element with the product
  for (int i = 0; i < size; ++i)
  {
    product *= arr[i];
  }

  return product;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  long long result = calculateProduct(arr, size);
  cout << "Product of all elements in the array: " << result << endl;

  return 0;
}
