#include <bits/stdc++.h>
using namespace std;

class Node // User defined data type
{
public:
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};

class Queue // User defined data structure
{
public:
  Node *head;
  Node *tail;
  int size;
  Queue()
  {
    head = tail = NULL;
    size = 0;
  }

  void push(int val)
  {
    Node *temp = new Node(val);
    if (size == 0)
      head = tail = temp;
    else
    {
      tail->next = temp;
      tail = temp;
    }
    size++;
  }

  void pop()
  {
    Node *temp = head;
    if (size == 0)
    {
      cout << "Queue is empty";
      return;
    }
    head = temp->next;
    delete temp; // wastage nhi ho rhi
    size--;
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

  int front()
  {
    if (size == 0)
    {
      cout << "Queue is empty";
      return -1;
    }
    return head->val;
  }
  int back()
  {
    if (size == 0)
    {
      cout << "Queue is empty";
      return -1;
    }
    return tail->val;
  }

  bool empty()
  {
    if (size == 0)
      return true;
    return false;
  }
};

int main()
{
  Queue q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.display();
  cout << q.front() << endl;
  cout << q.back() << endl;
  cout << q.size << endl;
  q.pop();
  cout << q.front() << endl;
  // q.reverse_display();
  q.display();
  cout << q.size << endl;
  return 0;
}