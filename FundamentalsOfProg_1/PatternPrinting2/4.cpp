#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Outer loop for rows
  for (int i = 0; i < n; i++)
  {
    // Inner loop for columns
    for (int j = 0; j < 2 * n - 1; j++)
    {
      if (i == 0 || j == 0 || j == 2 * n - 2)
      {
        cout << char('A' + j);
      }
      else
      {
        if (j >= n - i && j < n - 1 + i)
        {
          cout << " ";
        }
        else
        {
          cout << char('A' + j);
        }
      }
    }
    cout << endl;
  }

  return 0;
}
