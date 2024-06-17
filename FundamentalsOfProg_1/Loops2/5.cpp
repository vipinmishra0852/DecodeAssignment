#include <iostream>
using namespace std;

int main()
{
  // Input the number as a string
  string num;
  cout << "Enter a number: ";
  cin >> num;

  int sum = 0;

  // Iterate through each character in the string
  for (char digit : num)
  {
    // Convert character to integer
    int n = digit - '0';

    // Check if the digit is even
    if (n % 2 == 0)
    {
      sum += n; // Add to sum if even
    }
  }

  // Output the sum of even digits
  cout << "Sum of even digits: " << sum << endl;

  return 0;
}
/*
Enter a number: 4556
Sum of even digits: 10

*/
