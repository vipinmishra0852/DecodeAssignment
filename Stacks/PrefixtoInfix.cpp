#include <bits/stdc++.h>
using namespace std;
string solve(string val1, string val2, char c)
{
  string s = "";
  s = (val1 + c + val2);
  return s;
}

int main()
{
  string s = "-/*+79483";
  stack<string> st;
  int n = s.length();

  for (int i = n - 1; i >= 0; i--)
  {
    if (isdigit(s[i]))
      st.push(to_string(s[i] - '0')); // Push the numeric value onto the value stack
    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
    {
      char ch = s[i];
      string val1 = st.top();
      st.pop();
      string val2 = st.top();
      st.pop();
      string ans = solve(val1, val2, ch);
      st.push(ans);
    }
  }
  cout << st.top() << endl;
  cout << "7+9*4/8-3" << endl;
  return 0;
}