#include <iostream>
using namespace std;

int main()
{
  // Initialize the number of rows and columns
  const int rows = 5;
  const int cols = 5;

  // Create a 2D matrix with 5 rows and 5 columns
  int matrix[rows][cols];

  // Store the value 10 at every index
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      matrix[i][j] = 10;
    }
  }

  // Print the matrix
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
