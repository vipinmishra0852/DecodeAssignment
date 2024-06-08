#include <bits/stdc++.h>
using namespace std;
int solve(int val1, int val2, char c)
{
  if (c == '+')
    return (val1 + val2);
  else if (c == '-')
    return (val1 - val2);
  else if (c == '*')
    return (val1 * val2);
  else
    return (val1 / val2);
}

int main()
{
  string s = "-/*+79483";
  stack<int> st;
  int n = s.length();

  for (int i = n - 1; i >= 0; i--)
  {
    if (isdigit(s[i]))
      st.push((s[i] - '0')); // Push the numeric value onto the value stack
    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
    {
      char ch = s[i];
      int val1 = st.top();
      st.pop();
      int val2 = st.top();
      st.pop();
      int ans = solve(val1, val2, ch);
      st.push(ans);
    }
  }
  cout << st.top() << endl;
  return 0;
}