#include <bits/stdc++.h>

using namespace std;
int index(vector<int> &arr, int i, int n, int key)
{
  if (i == n)
  {
    return -1;
  }
  if (arr[i] == key)
  {
    return i;
  }
  return index(arr, i + 1, n, key);
}
int main()
{
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  cout << "ENter the element" << endl;
  cin >> k;
  cout << index(arr, 0, n, k);
}