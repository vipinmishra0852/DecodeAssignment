#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
    this->next = NULL;
  }
};

class Deque
{
public:
  Node *head;
  Node *tail;
  int size;
  Deque()
  {
    head = tail = NULL;
    size = 0;
  }
  void pushBack(int val)
  {
    Node *temp = new Node(val);
    if (size == 0)
      head = tail = temp;
    else
    {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
    size++;
  }

  void pushFront(int val)
  {
    Node *temp = new Node(val);
    if (size == 0)
      head = tail = temp;
    else
    {
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
    size++;
  }

  void popFront()
  {
    Node *temp = head;
    if (size == 0)
    {
      cout << "List is empty";
      return;
    }
    head = temp->next;
    if (head)
      head->prev = NULL;
    if (head == NULL)
      tail = NULL;
    delete temp;
    size--;
  }
  void popBack()
  {

    if (size == 0)
    {
      cout << "List is empty";
      return;
    }
    if (size == 1)
    {
      popFront();
      return;
    }
    Node *temp = tail->prev;
    temp->next = NULL;
    tail = temp;

    size--;
  }

  Node *deleteNode(Node *head, int target)
  {
    if (head->val == target)
    {
      head = head->next;
      return head;
    }

    Node *temp = head;

    while (temp->next->val != target)
    {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    size--;
    return head;
  }

  void display()
  {
    Node *temp = head;
    while (temp)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void displayRev()
  {
    Node *temp = tail;
    while (temp)
    {
      cout << temp->val << " ";
      temp = temp->prev;
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
  Deque q;
  q.pushFront(10);
  q.pushFront(20);
  q.pushFront(30);
  q.pushBack(40);
  q.pushBack(50);
  q.display();
  cout << q.front() << endl;
  cout << q.back() << endl;
  cout << q.size << endl;
  q.popFront();
  cout << q.front() << endl;
  q.displayRev();
  q.display();
  cout << q.size << endl;
  q.popBack();
  q.display();
  return 0;
}