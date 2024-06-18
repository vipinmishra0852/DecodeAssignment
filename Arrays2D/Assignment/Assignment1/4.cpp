#include <iostream>
using namespace std;

int main()
{
  // Define the dimensions of the matrix
  const int rows = 4;
  const int cols = 4;

  // Initialize the matrix
  int matrix[rows][cols] = {
      {1, 3, 4, 6},
      {2, 4, 5, 7},
      {3, 5, 6, 8},
      {4, 6, 7, 9}};

  // Initialize the variable to store the largest element
  int largest = matrix[0][0];

  // Iterate through the matrix to find the largest element
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] > largest)
      {
        largest = matrix[i][j];
      }
    }
  }

  // Print the largest element
  cout << "The largest element in the matrix is: " << largest << endl;

  return 0;
}
