#include <iostream>
using namespace std;

int main()
{
  // Define the dimensions of the matrix
  const int rows = 3;
  const int cols = 4;

  // Initialize the matrix
  int matrix[rows][cols] = {
      {1, 3, 5, 7},
      {3, 4, 7, 8},
      {1, 4, 12, 3}};

  // Initialize variables to track the maximum sum and the corresponding row index
  int maxSum = 0;
  int maxRow = 0;

  // Iterate through each row
  for (int i = 0; i < rows; i++)
  {
    int currentSum = 0;
    // Calculate the sum of the current row
    for (int j = 0; j < cols; j++)
    {
      currentSum += matrix[i][j];
    }
    // Update maxSum and maxRow if the current row has a greater sum
    if (currentSum > maxSum)
    {
      maxSum = currentSum;
      maxRow = i;
    }
  }

  // Print the row number with the maximum sum (1-based index)
  cout << "The row with the maximum sum is: " << maxRow + 1 << endl;

  return 0;
}
