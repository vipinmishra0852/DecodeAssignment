#include <iostream>
using namespace std;

void printFibonacci(int n)
{
  int fib1 = 1, fib2 = 1, fibNext;

  // Handle special case for n = 1
  if (n >= 1)
  {
    cout << fib1 << " ";
  }
  // Handle special case for n = 2
  if (n >= 2)
  {
    cout << fib2 << " ";
  }

  // Generate Fibonacci numbers from the 3rd to nth
  for (int i = 3; i <= n; ++i)
  {
    fibNext = fib1 + fib2;
    cout << fibNext << " ";

    // Update values for next iteration
    fib1 = fib2;
    fib2 = fibNext;
  }
}

int main()
{
  // Input the number of Fibonacci numbers to print
  int n;
  cout << "Enter the number of Fibonacci numbers to print: ";
  cin >> n;

  // Print first 'n' Fibonacci numbers
  printFibonacci(n);

  return 0;
}
