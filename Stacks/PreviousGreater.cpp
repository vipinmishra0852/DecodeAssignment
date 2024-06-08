#include <bits/stdc++.h>
using namespace std;
int main()
{
  stack<int> st;
  // Using pop , ans , push
  // SC O(n) //TC O(n);
  int n = 8;
  int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
  int pge[] = {-1, -1, -1, -1, -1, -1, -1, -1};
  pge[0] = -1;
  st.push(arr[0]);
  for (int i = 1; i < n; i++)
  { // pop all the answer in nge array
    while (st.size() > 0 && st.top() <= arr[i])
    {
      st.pop();
    }
    if (st.size() == 0)
      pge[i] = -1;
    else
    {
      // push the element
      pge[i] = st.top();
    }
    st.push(arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    cout << pge[i] << " ";
  }
  cout << endl;
  return 0;
}