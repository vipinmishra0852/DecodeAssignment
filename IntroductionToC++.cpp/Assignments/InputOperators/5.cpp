#include <iostream>
using namespace std;

int main()
{
  char char1, char2;

  // Taking two characters as input from the user
  cout << "Enter the first character: ";
  cin >> char1;
  cout << "Enter the second character: ";
  cin >> char2;

  // Calculating the difference between their ASCII values
  int difference = static_cast<int>(char1) - static_cast<int>(char2);

  // Displaying the result
  cout << "The difference between ASCII values of '" << char1 << "' and '" << char2 << "' is: " << difference << endl;

  return 0;
}
