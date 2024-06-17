
#include <iostream>
using namespace std;

int main()
{
  char ch = 'A'; // Start with 'A' for uppercase letters

  cout << "ASCII values and characters of 26 alphabets (uppercase and lowercase):" << endl;

  // Print uppercase letters ('A' to 'Z')
  while (ch <= 'Z')
  {
    cout << "ASCII value of " << ch << " is " << int(ch) << endl;
    ch++;
  }

  ch = 'a'; // Reset to 'a' for lowercase letters

  // Print lowercase letters ('a' to 'z')
  while (ch <= 'z')
  {
    cout << "ASCII value of " << ch << " is " << int(ch) << endl;
    ch++;
  }

  return 0;
}