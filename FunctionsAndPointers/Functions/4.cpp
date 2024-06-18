#include <iostream>
#include <cmath> // for pow

using namespace std;

// Function to count the number of digits in a number
int countDigits(int number)
{
  int count = 0;
  if (number == 0)
  {
    return 1; // 0 has 1 digit
  }
  if (number < 0)
  {
    number = -number; // make the number positive if it's negative
  }
  while (number != 0)
  {
    number /= 10;
    count++;
  }
  return count;
}

// Function to print the square of a number
void printSquare(int number)
{
  int square = number * number;
  cout << "The square of " << number << " is " << square << endl;
}

int main()
{
  int number;
  cout << "Enter a number: ";
  cin >> number;

  int digitCount = countDigits(number);
  cout << "The number of digits in " << number << " is " << digitCount << endl;

  printSquare(number);

  return 0;
}
