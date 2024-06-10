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
}
void reverse(queue<int> &q)
{
  stack<int> helper;
  int n = q.size();
  for (int i = 0; i < n; i++)
  {
    int x = q.front();
    q.pop();
    helper.push(x);
  }
  while (!helper.empty())
  {
    q.push(helper.top());
    helper.pop();
  }
}

int main()
{
  queue<int> q;
  // push , pop , front , back , size , empty
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  // cout << q.front();
  // q.pop();
  display(q);
  reverse(q);
  display(q);
  return 0;
}