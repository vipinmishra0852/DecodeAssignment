#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateSpiralMatrix(int n)
{
  // Initialize the matrix with zeros
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  int num = 1; // Start with the smallest number
  int top = 0, bottom = n - 1, left = 0, right = n - 1;

  while (num <= n * n)
  {
    // Traverse from left to right along the top row
    for (int i = left; i <= right; i++)
    {
      matrix[top][i] = num++;
    }
    top++; // Move to the next row

    // Traverse from top to bottom along the rightmost column
    for (int i = top; i <= bottom; i++)
    {
      matrix[i][right] = num++;
    }
    right--; // Move to the previous column

    // Traverse from right to left along the bottom row
    for (int i = right; i >= left; i--)
    {
      matrix[bottom][i] = num++;
    }
    bottom--; // Move to the previous row

    // Traverse from bottom to top along the leftmost column
    for (int i = bottom; i >= top; i--)
    {
      matrix[i][left] = num++;
    }
    left++; // Move to the next column
  }

  return matrix;
}

void printMatrix(vector<vector<int>> &matrix)
{
  for (const auto &row : matrix)
  {
    for (int num : row)
    {
      cout << num << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n;

  // Input the size of the matrix
  cout << "Enter the size of the matrix (n): ";
  cin >> n;

  // Generate the spiral matrix
  vector<vector<int>> spiralMatrix = generateSpiralMatrix(n);

  // Print the spiral matrix
  cout << "Spiral Matrix:" << endl;
  printMatrix(spiralMatrix);

  return 0;
}
