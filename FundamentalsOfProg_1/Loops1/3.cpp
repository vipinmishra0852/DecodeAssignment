#include <iostream>
using namespace std;

int main()
{
  int n;

  // Prompt user to enter a number
  cout << "Enter a number to print its multiplication table: ";
  cin >> n;

  // Print the multiplication table of n
  cout << "Multiplication table of " << n << ":" << endl;
  for (int i = 1; i <= 10; ++i)
  {
    cout << n << " * " << i << " = " << n * i << endl;
  }

  return 0;
}