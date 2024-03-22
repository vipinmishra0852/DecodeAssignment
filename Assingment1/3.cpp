#include <bits/stdc++.h>
using namespace std;
bool power(int n)
{
  if (n == 1)
    return true;
  if (n % 2 == 0)
  {
    return power(n / 2);
  }
  return false;
}
int main()
{
  int n;
  cin >> n;

  if (power(n))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}