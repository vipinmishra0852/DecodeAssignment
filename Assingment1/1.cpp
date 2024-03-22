#include <bits/stdc++.h>
using namespace std;

int sum1(int a, int b)
{
  if (a > b)
  {
    return 0;
  }
  if (a % 2 != 0)
  {

    return a + sum1(a + 2, b);
    ;
  }
  else
  {

    return sum1(a + 1, b);
  }
}

int main()
{
  int a, b;
  cout << "Enter the number a and b " << endl;
  cin >> a >> b;
  int ans = sum1(a, b);
  cout << ans << endl;
  return 0;
}