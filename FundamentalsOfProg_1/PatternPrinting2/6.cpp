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
    // Inner loop for columns
    for (int j = 0; j < 2 * n - 1; ++j)
    {
      if (j == i || j == 2 * n - 2 - i)
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
