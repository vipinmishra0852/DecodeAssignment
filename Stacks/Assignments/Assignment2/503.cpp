#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &v)
  {
    int n = v.size();
    vector<int> helper(2 * n, -1);
    for (int i = 0; i < n; i++)
    {
      helper[i] = v[i];
    }
    int j = 0;
    for (int i = n; i < 2 * n; i++)
    {
      helper[i] = v[j];
      j++;
    }

       stack<int> st;
    vector<int> nge(2 * n);
    nge[2 * n - 1] = -1;
    st.push(helper[2 * n - 1]);
    for (int i = 2 * n - 2; i >= 0; i--)
    {
      while (st.size() > 0 && st.top() <= helper[i])
      {
        st.pop();
      }
      if (st.size() == 0)
      {
        nge[i] = -1;
      }
      else
      {
        nge[i] = st.top();
      }
      st.push(helper[i]);
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
      ans[i] = nge[i];
    }
    return ans;
  }
};

int main()
{

  Solution s;
  vector<int> v = {1, 2, 1};
  vector<int> ans;
  ans = s.nextGreaterElements(v);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}