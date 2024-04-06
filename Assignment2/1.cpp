#include <bits/stdc++.h>
using namespace std;
void printElementsInReverse(vector<int> &arr, int n)
{
  if (n < 0)
  {
    return;
  }

  cout << arr[n] << " ";
  printElementsInReverse(arr, n - 1);
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  printElementsInReverse(arr, n - 1);
  return 0;
}