#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n = 8;
  int stocks[n] = {100, 80, 60, 81, 70, 60, 75, 85};
  int a = -1;
  cout << 1 - a << endl;
  stack<int> st;
  int pgi[n];
  pgi[0] = 1;
  st.push(0);
  for (int i = 0; i < n; i++)
  {
    cout << stocks[i] << " ";
  }
  for (int i = 1; i < n; i++)
  {
    while (st.size() > 0 && stocks[st.top()] <= stocks[i])
    {
      st.pop();
    }

    if (st.size() == 0)
      pgi[i] = -1;
    else
    {
      pgi[i] = st.top();
    }

    pgi[i] = i - pgi[i];
    st.push(i);
  }

  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << pgi[i] << " ";
  }

  return 0;
}