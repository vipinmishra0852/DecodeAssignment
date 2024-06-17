#include <iostream>
using namespace std;

int main()
{
  cout << "Numbers from 1 to 100 divisible by 3:" << endl;

  // Loop through numbers from 1 to 100
  for (int i = 1; i <= 100; i++)
  {
    // Check if the number is divisible by 3
    if (i % 3 == 0)
    {
      // Print the number
      cout << i << " ";
    }
  }

  cout << endl; // Print a newline after all divisible numbers are printed
  return 0;
}