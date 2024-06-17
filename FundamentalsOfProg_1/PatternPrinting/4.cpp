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
    // Check if the row number is odd or even
    if (i % 2 != 0)
    {
      // Row contains numbers 1 to 2*i - 1
      for (int j = 1; j <= i; ++j)
      {
        cout << j << " ";
      }
    }
    else
    {
      // Row contains letters 'A' to 'A' + i - 1
      for (int j = 0; j < i; ++j)
      {
        cout << char('A' + j) << " ";
      }
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
