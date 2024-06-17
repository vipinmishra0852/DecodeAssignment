#include <iostream>
using namespace std;

int main()
{
  int m, n;
  cout << "Enter the number of rows (m): ";
  cin >> m;
  cout << "Enter the number of columns (n): ";
  cin >> n;

  // Calculate the step size for placing asterisks
  int step = n / m;

  // Outer loop for rows
  for (int i = 0; i < m; ++i)
  {
    // Inner loop for columns
    for (int j = 0; j < n; ++j)
    {
      if (j == (i * step) || j == (n - 1 - i * step))
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
