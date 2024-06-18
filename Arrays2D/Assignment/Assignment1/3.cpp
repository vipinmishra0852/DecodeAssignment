#include <iostream>
using namespace std;

int sumSubmatrix(int matrix[][4], int l1, int r1, int l2, int r2)
{
  int sum = 0;
  for (int i = l1; i <= l2; i++)
  {
    for (int j = r1; j <= r2; j++)
    {
      sum += matrix[i][j];
    }
  }
  return sum;
}

int main()
{
  // Define the matrix and its dimensions
  int n = 4, m = 4;
  int matrix[4][4] = {
      {1, 2, -3, 4},
      {0, 0, -4, 2},
      {1, -1, 2, 3},
      {-4, -5, -7, 0}};

  // Define the coordinates
  int l1 = 1, r1 = 2, l2 = 3, r2 = 3;

  // Get the sum of the submatrix
  int result = sumSubmatrix(matrix, l1, r1, l2, r2);

  // Print the result
  cout << "Sum of submatrix: " << result << endl;

  return 0;
}
