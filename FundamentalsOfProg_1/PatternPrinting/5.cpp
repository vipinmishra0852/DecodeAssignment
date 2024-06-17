#include <iostream>
using namespace std;

int main()
{
  // Input the value of n
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Print the upper half of the pattern
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }
    cout << endl;
  }

  // Print the lower half of the pattern
  for (int i = n - 1; i >= 1; --i)
  {
    for (int j = 1; j <= i; ++j)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
