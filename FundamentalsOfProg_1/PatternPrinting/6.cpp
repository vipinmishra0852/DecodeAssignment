#include <iostream>
using namespace std;

int main()
{
  // Input the values of m and n
  int m, n;
  cout << "Enter the number of rows (m): ";
  cin >> m;
  cout << "Enter the number of columns (n): ";
  cin >> n;

  // Print the top row with asterisks
  for (int i = 1; i <= n; ++i)
  {
    cout << "*";
  }
  cout << endl;

  // Print the middle rows with asterisks at the beginning and end
  for (int i = 2; i <= m - 1; ++i)
  {
    cout << "*";
    for (int j = 2; j <= n - 1; ++j)
    {
      cout << " ";
    }
    cout << "*";
    cout << endl;
  }

  // Print the bottom row with asterisks
  for (int i = 1; i <= n; ++i)
  {
    cout << "*";
  }
  cout << endl;

  return 0;
}
