#include <iostream>
using namespace std;

// Function to calculate the power of a number
int power(int base, int exponent)
{
  int result = 1;
  for (int i = 0; i < exponent; ++i)
  {
    result *= base;
  }
  return result;
}

// Function to check if a number is Armstrong number
bool isArmstrong(int num)
{
  int originalNum = num;
  int numDigits = 0;
  int sum = 0;

  // Count number of digits
  while (num != 0)
  {
    numDigits++;
    num /= 10;
  }

  // Reset num to original number
  num = originalNum;

  // Calculate sum of cubes of digits
  while (num != 0)
  {
    int digit = num % 10;
    sum += power(digit, numDigits);
    num /= 10;
  }

  // Check if sum of cubes of digits equals original number
  return (sum == originalNum);
}

int main()
{
  cout << "Armstrong numbers between 1 and 500:" << endl;
  for (int i = 1; i <= 500; ++i)
  {
    if (isArmstrong(i))
    {
      cout << i << endl;
    }
  }
  return 0;
}
