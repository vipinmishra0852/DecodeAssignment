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
    // Print letters from 'A' to 'A' + i - 1
    for (int j = 0; j < i; ++j)
    {
      cout << char('A' + j) << " ";
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
