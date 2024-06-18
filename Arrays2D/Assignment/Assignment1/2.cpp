#include <iostream>
using namespace std;

int main()
{
  // Define the size of the matrices
  const int rows = 3;
  const int cols = 3;

  // Initialize the two matrices
  int matrix1[rows][cols] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  int matrix2[rows][cols] = {
      {4, 5, 8},
      {0, 0, 8},
      {1, 2, 0}};

  // Add the two matrices and store the result in matrix1
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      matrix1[i][j] += matrix2[i][j];
    }
  }

  // Print the result matrix (matrix1)
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
