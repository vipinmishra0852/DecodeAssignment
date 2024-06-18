#include <iostream>
using namespace std;

// Function to display the middle row and middle column
void displayMiddleRowAndColumn(int matrix[][5], int size)
{
  int middle = size / 2;

  // Display middle column elements
  cout << "Middle column elements: " << endl;
  for (int i = 0; i < size; i++)
  {
    cout << matrix[i][middle] << endl;
  }

  // Display middle row elements
  cout << "Middle row elements: " << endl;
  for (int j = 0; j < size; j++)
  {
    cout << matrix[middle][j] << " ";
  }
  cout << endl;
}

int main()
{
  // Define the size of the matrix
  const int size = 5;

  // Initialize the matrix
  int matrix[size][size] = {
      {1, 2, 3, 4, 5},
      {3, 4, 5, 6, 7},
      {7, 6, 5, 4, 3},
      {8, 7, 6, 5, 4},
      {1, 2, 37, 8, 0}};

  // Call the function to display the middle row and column
  displayMiddleRowAndColumn(matrix, size);

  return 0;
}
