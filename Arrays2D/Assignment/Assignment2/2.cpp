#include <iostream>
using namespace std;

void rotateMatrix(int matrix[][3], int size)
{
  // Transpose the matrix
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse elements in each row
  for (int i = 0; i < size; i++)
  {
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
      swap(matrix[i][left], matrix[i][right]);
      left++;
      right--;
    }
  }
}

void printMatrix(int matrix[][3], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // Define the size of the matrix
  const int size = 3;

  // Initialize the matrix
  int matrix[size][size] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  // Rotate the matrix
  rotateMatrix(matrix, size);

  // Print the rotated matrix
  cout << "Rotated matrix:" << endl;
  printMatrix(matrix, size);

  return 0;
}
