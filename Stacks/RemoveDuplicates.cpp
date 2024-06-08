#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s)
{
  stack<char> st;
  int n = s.size();
  st.push(s[0]);
  for (int i = 1; i < n; i++)
  {
    if (st.top() != s[i])
      st.push(s[i]);
  }
  string ans = "";
  n = st.size();
  for (int i = 0; i < n; i++)
  {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  string s = "aaabbbccceddddddd";
  cout << removeDuplicates(s);
  return 0;
}