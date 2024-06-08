#include <bits/stdc++.h>
using namespace std;
int main()
{
  stack<int> st;
  // Using pop , ans , push
  // SC O(n) //TC O(n);
  int n = 8;
  int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
  int nge[] = {-1, -1, -1, -1, -1, -1, -1, -1};
  nge[n - 1] = -1;
  st.push(arr[n - 1]);
  for (int i = n - 2; i >= 0; i--)
  { // pop all the answer in nge array
    while (st.size() > 0 && st.top() <= arr[i])
    {
      st.pop();
    }
    if (st.size() == 0)
      nge[i] = -1;
    else
    {
      // push the element
      nge[i] = st.top();
    }
    st.push(arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    cout << nge[i] << " ";
  }
  cout << endl;
  return 0;
}