#include <iostream>
using namespace std;

int main()
{
  // Input the value of n
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  // Iterate through each row
  for (int i = n; i >= 1; --i)
  {
    // Print numbers from 1 to i
    for (int j = 1; j <= i; ++j)
    {
      cout << j << " ";
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
