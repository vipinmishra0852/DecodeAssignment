#include <iostream>
using namespace std;

int main()
{
  int a, b;

  // Taking two integers as input from the user
  cout << "Enter the first integer: ";
  cin >> a;
  cout << "Enter the second integer: ";
  cin >> b;

  // Checking which number is the largest and displaying the result
  if (a > b)
  {
    cout << "First number " << a << " is the largest." << endl;
  }
  else
  {
    cout << "Second number " << b << " is the largest." << endl;
  }

  return 0;
}
