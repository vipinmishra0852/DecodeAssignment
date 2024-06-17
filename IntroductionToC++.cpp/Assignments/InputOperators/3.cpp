#include <iostream>
using namespace std;
int main()
{
  int x, y;
  cin >> x >> y; // 2 3
  x += y;        // 5 3
  x -= y;        // 2 3
  x %= y;        // 2 3
  cout << x;     // 2
}