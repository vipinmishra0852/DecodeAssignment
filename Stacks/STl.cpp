#include <bits/stdc++.h>
using namespace std;

void reverse_display(stack<int> t)
{
  stack<int> helper;
  cout << "Printing the stack in reverse order" << endl;
  while (t.size() > 0)
  {
    cout << t.top() << " ";
    helper.push(t.top());
    t.pop();
  }
  cout << endl;
  while (helper.size() > 0)
  {
    t.push(helper.top());
    helper.pop();
  }
  cout << endl;
}
void display(stack<int> t)
{
  stack<int> helper;
  while (t.size() > 0)
  {
    helper.push(t.top());
    t.pop();
  }
  cout << "Printing the stack  " << endl;
  while (helper.size() > 0)
  {
    cout << helper.top() << " ";
    t.push(helper.top());
    helper.pop();
  }
  cout << endl;
}
void recursive_rev_display(stack<int> &s)
{
  if (s.size() == 0)
    return;
  int x = s.top();
  cout << x << " ";
  s.pop();
  recursive_rev_display(s);
  s.push(x);
}
void recursive_display(stack<int> &s)
{
  if (s.size() == 0)
    return;
  int x = s.top();
  s.pop();
  recursive_display(s);
  cout << x << " ";
  s.push(x);
}

void enter_at_bottom(stack<int> &s, int val)
{
  stack<int> temp;
  while (s.size() > 0)
  {
    temp.push(s.top());
    s.pop();
  }
  s.push(val);
  while (temp.size() > 0)
  {
    s.push(temp.top());
    temp.pop();
  }
}
void recursive_bottom_push(stack<int> &s, int val)
{
  if (s.size() == 0)
  {
    s.push(val);
    return;
  }
  int x = s.top();
  s.pop();
  recursive_bottom_push(s, val);
  s.push(x);
}
void push_at_idx(stack<int> &s, int val, int idx)
{
  stack<int> helper;
  while (s.size() > idx)
  {
    helper.push(s.top());
    s.pop();
  }
  s.push(val);
  while (helper.size() > 0)
  {
    s.push(helper.top());
    helper.pop();
  }
}

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  display(s);
  enter_at_bottom(s, 70);
  display(s);
  reverse_display(s);
  push_at_idx(s, 100, 2);
  display(s);
  reverse_display(s);
  recursive_rev_display(s);
  cout << endl;
  recursive_display(s);
  cout << endl;
  recursive_bottom_push(s, 98);
  recursive_display(s);
  return 0;
}