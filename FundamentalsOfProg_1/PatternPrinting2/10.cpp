#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int totalCols = 2 * n;

  // Upper part including the middle line
  for (int i = 1; i <= n; ++i)
  {
    // Print left side of the pattern
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }

    // Print spaces in the middle
    int spaces = totalCols - 2 * i;
    for (int j = 1; j <= spaces; ++j)
    {
      cout << " ";
    }

    // Print right side of the pattern
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }

    cout << endl;
  }

  // Lower part excluding the middle line
  for (int i = n - 1; i >= 1; --i)
  {
    // Print left side of the pattern
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }

    // Print spaces in the middle
    int spaces = totalCols - 2 * i;
    for (int j = 1; j <= spaces; ++j)
    {
      cout << " ";
    }

    // Print right side of the pattern
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }

    cout << endl;
  }

  return 0;
}
