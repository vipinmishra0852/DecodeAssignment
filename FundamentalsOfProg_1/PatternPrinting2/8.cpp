#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Outer loop for rows
  for (int i = 1; i <= n; ++i)
  {
    // Print leading spaces
    for (int j = 1; j <= n - i; ++j)
    {
      cout << " ";
    }

    // Print the first number
    cout << i;

    // Print spaces between the numbers
    for (int j = 1; j < 2 * (i - 1); ++j)
    {
      cout << " ";
    }

    // Print the second number if it's not the first row
    if (i > 1)
    {
      cout << i;
    }

    cout << endl;
  }

  return 0;
}
