#include <iostream>
using namespace std;

void printOddNumbers(int a, int b)
{
  // Ensure a is less than or equal to b
  if (a > b)
  {
    swap(a, b);
  }

  // Loop from a to b
  for (int i = a; i <= b; ++i)
  {
    // Check if the number is odd
    if (i % 2 != 0)
    {
      cout << i << " ";
    }
  }
  cout << endl;
}

int main()
{
  int a, b;
  cout << "Enter two numbers a and b: ";
  cin >> a >> b;

  cout << "Odd numbers between " << a << " and " << b << " are: ";
  printOddNumbers(a, b);

  return 0;
}
