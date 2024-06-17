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
    // Print numbers from i to 1
    for (int j = i; j >= 1; --j)
    {
      cout << j << " ";
    }
    // Move to the next line after each row
    cout << endl;
  }

  return 0;
}
