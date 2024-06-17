#include <iostream>
using namespace std;

int main()
{
  // Input the value of n
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Iterate through each row
  for (int i = 1; i <= n; ++i)
  {
    // Print spaces for alignment
    for (int j = 1; j <= 2 * (n - i); ++j)
    {
      cout << " ";
    }
    // Print letters from 'A' to 'A' + i - 1
    for (int j = 0; j < 2 * i - 1; ++j)
    {
      cout << char('A' + j);
      if (j < 2 * i - 2)
      {
        cout << " ";
      }
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
