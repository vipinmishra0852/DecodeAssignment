#include <iostream>
using namespace std;

int main()
{
  int test = 0;

  // Output the string "First character " followed by the character literal '1'
  cout << "First character " << '1' << endl; // Output: First character 1

  // Output the string "Second character " followed by the result of the conditional expression (test ? 3 : '1')
  cout << "Second character " << (test ? 3 : '1') << endl; // Output: Second character 1

  return 0;
}
