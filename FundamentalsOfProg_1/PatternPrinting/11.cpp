#include <iostream>
using namespace std;

int main()
{
  // Input the value of n (number of rows in the middle part)
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Print the upper half of the diamond
  for (int i = 1; i <= n; ++i)
  {
    // Print spaces before asterisks
    for (int j = 1; j <= n - i; ++j)
    {
      cout << " ";
    }
    // Print asterisks
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }
    cout << endl;
  }

  // Print the lower half of the diamond
  for (int i = n - 1; i >= 1; --i)
  {
    // Print spaces before asterisks
    for (int j = 1; j <= n - i; ++j)
    {
      cout << " ";
    }
    // Print asterisks
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
