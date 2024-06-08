#include <bits/stdc++.h>
using namespace std;
class Stack
{

public:
  vector<int> v;
  Stack()
  {
  }

  void push(int val)
  {
    v.push_back(val);
  }
  void pop()
  {
    if (v.size() == 0)
    {
      cout << "Stack is empty !!" << endl;
      return;
    }
    v.pop_back();
  }

  int top()
  {
    if (v.size() == 0)
    {
      cout << "Stack is empty !!" << endl;
      return -1;
    }
    return v[v.size() - 1];
  }
  int size()
  {
    return v.size();
  }
};

void display(Stack s)
{
  while (s.size() > 0)
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  display(s);
  cout << s.top();
  s.pop();
  display(s);
  return 0;
}