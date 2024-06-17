#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Outer loop for rows
  for (int i = 0; i < n; ++i)
  {
    // Print the left side of the pattern
    for (int j = 1; j <= n - i; ++j)
    {
      cout << j << " ";
    }

    // Print the middle spaces
    for (int j = 0; j < 2 * i; ++j)
    {
      cout << "  ";
    }

    // Print the right side of the pattern
    if (i > 0)
    {
      for (int j = n - i; j >= 1; --j)
      {
        cout << j;
        if (j > 1)
        {
          cout << " ";
        }
      }
    }
    else
    {
      for (int j = n - 1; j >= 1; --j)
      {
        cout << j << " ";
      }
    }

    cout << endl;
  }

  return 0;
}
