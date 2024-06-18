#include <iostream>
using namespace std;

void displayDiagonals(int matrix[][3], int size)
{
  // Print the primary diagonal elements
  cout << "Primary diagonal elements:" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << matrix[i][i] << " ";
  }
  cout << endl;

  // Print the secondary diagonal elements
  cout << "Secondary diagonal elements:" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << matrix[i][size - 1 - i] << " ";
  }
  cout << endl;
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

  // Call the function to display the diagonals
  displayDiagonals(matrix, size);

  return 0;
}
