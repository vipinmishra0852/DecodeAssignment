#include <iostream>
using namespace std;

int main()
{
  int year;

  // Taking the year as input from the user
  cout << "Enter a year: ";
  cin >> year;

  // Checking if the year is a leap year
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    cout << "yes" << endl;
  }
  else
  {
    cout << "no" << endl;
  }

  return 0;
}
