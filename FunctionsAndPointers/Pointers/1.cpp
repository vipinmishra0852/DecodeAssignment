#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a = 5;
  int b = 4;
  int *c = &a;
  int *d = &b;
  cout << (*c) * (*d) << endl;

  return 0;
}