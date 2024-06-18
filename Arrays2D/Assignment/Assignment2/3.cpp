#include <iostream>
using namespace std;

void printWaveForm(int matrix[][3], int rows, int cols)
{
  // Iterate over each column
  for (int j = 0; j < cols; j++)
  {
    // Check if column is even or odd
    if (j % 2 == 0)
    {
      // Column is even: top to bottom
      for (int i = 0; i < rows; i++)
      {
        cout << matrix[i][j] << " ";
      }
    }
    else
    {
      // Column is odd: bottom to top
      for (int i = rows - 1; i >= 0; i--)
      {
        cout << matrix[i][j] << " ";
      }
    }
  }
  cout << endl;
}

int main()
{
  // Define the size of the matrix
  const int rows = 3;
  const int cols = 3;

  // Initialize the matrix
  int matrix[rows][cols] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  // Print the matrix in wave form
  cout << "Matrix in wave form:" << endl;
  printWaveForm(matrix, rows, cols);

  return 0;
}
