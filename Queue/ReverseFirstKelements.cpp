#include <bits/stdc++.h>
using namespace std;

void reverseK(int k, queue<int> &q)
{
  int n = q.size();
  stack<int> st;
  for (int i = 1; i <= k; i++)
  {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }
  for (int i = 1; i <= n - k; i++)
  {
    q.push(q.front());
    q.pop();
  }
}
void display(queue<int> &q)
{
  int n = q.size();
  for (int i = 0; i < n; i++)
  {
    int x = q.front();
    cout << x << " ";
    q.pop();
    q.push(x);
  }
  cout << endl;
}

int main()
{
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  int k = 5;
  display(q);
  reverseK(k, q);
  display(q);

  return 0;
}