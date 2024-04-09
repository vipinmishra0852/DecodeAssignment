#include <bits/stdc++.h>
using namespace std;

int reverse(int n, int ans)
{
  if (n == 0)
    return ans;
  int s = n % 10;
  ans = ans * 10 + s;
  return reverse(n / 10, ans);
}

int main()
{
  int n = 12034;
  ;
  cout << reverse(n, 0);
  return 0;
}
