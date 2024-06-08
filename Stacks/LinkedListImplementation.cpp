#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  Node *next;
  int val;
  Node(int val)
  {
    this->next = NULL;
    this->val = val;
  }
};

class Stack
{
public:
  Node *head;
  int size;
  Stack()
  {
    head = NULL;
    size = 0;
  }
  void push(int val)
  {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    size++;
  }
  void pop()
  {
    if (head == NULL)
    {
      cout << "Stack is Empty " << endl;
      return;
    }
    head = head->next;
    size--;
  }
  int top()
  {
    if (head == NULL)
    {
      cout << "Stack is Empty " << endl;
      return -1;
    }
    return head->val;
  }
  void display()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void rec_display(Node *head)
  {
    if (head == NULL)
      return;
    rec_display(head->next);
    cout << head->val << " ";
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  cout << s.top() << endl;
  s.display();
  cout << s.size << endl;
  s.rec_display(s.head);
  cout << endl;
  s.display();
  return 0;
}