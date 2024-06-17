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
    for (int j = 1; j <= n - i; ++j)
    {
      cout << " ";
    }
    // Print asterisks for the pattern
    for (int j = 1; j <= n; ++j)
    {
      cout << "*";
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
