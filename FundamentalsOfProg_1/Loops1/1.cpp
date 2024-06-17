#include <iostream>
using namespace std;

int main()
{
  cout << "Odd numbers from 1 to 100:" << endl;

  // Loop through numbers from 1 to 100
  for (int i = 1; i <= 100; i++)
  {
    // Check if the number is odd
    if (i % 2 != 0)
    {
      // Print the odd number
      cout << i << " ";
    }
  }

  cout << endl; // Print a newline after all odd numbers are printed
  return 0;
}