#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
  int m = matrix.size();
  int n = matrix[0].size();

  bool firstRowZero = false;
  bool firstColZero = false;

  // Check if the first row should be zeroed
  for (int j = 0; j < n; j++)
  {
    if (matrix[0][j] == 0)
    {
      firstRowZero = true;
      break;
    }
  }

  // Check if the first column should be zeroed
  for (int i = 0; i < m; i++)
  {
    if (matrix[i][0] == 0)
    {
      firstColZero = true;
      break;
    }
  }

  // Use the first row and first column to mark zeros
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (matrix[i][j] == 0)
      {
        matrix[i][0] = 0; // Mark the corresponding row
        matrix[0][j] = 0; // Mark the corresponding column
      }
    }
  }

  // Set entire rows to zero based on first column marks
  for (int i = 1; i < m; i++)
  {
    if (matrix[i][0] == 0)
    {
      for (int j = 1; j < n; j++)
      {
        matrix[i][j] = 0;
      }
    }
  }

  // Set entire columns to zero based on first row marks
  for (int j = 1; j < n; j++)
  {
    if (matrix[0][j] == 0)
    {
      for (int i = 1; i < m; i++)
      {
        matrix[i][j] = 0;
      }
    }
  }

  // Set first row to zero if needed
  if (firstRowZero)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[0][j] = 0;
    }
  }

  // Set first column to zero if needed
  if (firstColZero)
  {
    for (int i = 0; i < m; i++)
    {
      matrix[i][0] = 0;
    }
  }
}

void printMatrix(const vector<vector<int>> &matrix)
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
  vector<vector<int>> matrix = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};

  cout << "Input Matrix:" << endl;
  printMatrix(matrix);

  setZeroes(matrix);

  cout << "\nOutput Matrix:" << endl;
  printMatrix(matrix);

  return 0;
}
