#include <iostream>
using namespace std;

int main()
{
  int a = 10, b = 20;
  int *ptr = &a;                        // ptr now points to a
  b = *ptr + 1;                         // b is assigned the value of *ptr (which is a) + 1, so b = 10 + 1 = 11
  ptr = &b;                             // ptr now points to b
  cout << *ptr << ' ' << a << ' ' << b; // Output the value pointed to by ptr, a, and b
  return 0;
}
// OutPut:: 11 10 11
