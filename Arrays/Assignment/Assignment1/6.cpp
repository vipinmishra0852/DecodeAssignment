#include <iostream>
using namespace std;

int main()
{
  int sub[50], i;

  // Incorrect for loop with unintended semicolon
  for (i = 0; i <= 48; i++)
    ;
  {
    sub[i] = i;
    cout << sub[i] << endl;
  }

  return 0;
}
