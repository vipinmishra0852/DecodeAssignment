#include <iostream>
using namespace std;

// Function to reverse a given integer
int reverseNumber(int num)
{
  int reversed = 0;
  while (num > 0)
  {
    int digit = num % 10;
    reversed = reversed * 10 + digit;
    num /= 10;
  }
  return reversed;
}

int main()
{
  // Input the number
  int number;
  cout << "Enter a number: ";
  cin >> number;

  // Calculate the reverse of the number
  int reversedNumber = reverseNumber(number);

  // Calculate the sum of the number and its reverse
  int sum = number + reversedNumber;

  // Output the sum
  cout << "Sum of " << number << " and its reverse (" << reversedNumber << ") is: " << sum << endl;

  return 0;
}
