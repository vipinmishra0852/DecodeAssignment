#include <bits/stdc++.h>
using namespace std;

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
void reorder(queue<int> &q)
{
  int n = q.size();
  stack<int> st;
  for (int i = 1; i <= n / 2; i++)
  {
    st.push(q.front());
    q.pop();
  }

  while (st.size() > 0)
  {
    q.push(st.top());
    st.pop();
  }

  for (int i = 1; i <= n / 2; i++)
  {
    st.push(q.front());
    q.pop();
  }

  while (st.size() > 0)
  {
    q.push(st.top());
    st.pop();
    q.push(q.front());
    q.pop();
  }

  while (q.size() > 0)
  {
    st.push(q.front());
    q.pop();
  }
  while (st.size() > 0)
  {
    q.push(st.top());
    st.pop();
  }
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
  q.push(70);
  q.push(80);
  display(q); // 10 20 30 40 50 60 70 80

  reorder(q);
  display(q); // 10 50 20 60 30 70 40 80
  return 0;
}