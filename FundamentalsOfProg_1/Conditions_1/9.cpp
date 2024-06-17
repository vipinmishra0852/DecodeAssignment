#include <iostream>
using namespace std;

int main()
{
  char ch;

  // Taking a character as input from the user
  cout << "Enter a character: ";
  cin >> ch;

  // Checking if the character is an alphabet
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
  {
    cout << "Alphabet" << endl;
  }
  // Checking if the character is a digit
  else if (ch >= '0' && ch <= '9')
  {
    cout << "Digit" << endl;
  }
  // If it is neither alphabet nor digit, then it is a special character
  else
  {
    cout << "Special character" << endl;
  }

  return 0;
}
