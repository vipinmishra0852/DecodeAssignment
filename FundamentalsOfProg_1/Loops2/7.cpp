#include <iostream>
using namespace std;

// Function to calculate factorial of a number
unsigned long long factorial(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  unsigned long long fact = 1;
  for (int i = 2; i <= n; ++i)
  {
    fact *= i;
  }
  return fact;
}

int main()
{
  // Input the number of factorials to print
  int n;
  cout << "Enter the number of factorials to print: ";
  cin >> n;

  // Print factorials of first 'n' numbers
  for (int i = 1; i <= n; ++i)
  {
    cout << factorial(i) << endl;
  }

  return 0;
}
