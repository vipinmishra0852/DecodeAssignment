#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  Node *next;
  Node *prev;
  int val;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

class CircularList
{
public:
  Node *head;
  Node *tail;
  int size = 0;
  CircularList()
  {
    head = tail = NULL;
    size = 0;
  }
  void insertAtTail(int val)
  {
    Node *temp = new Node(val);
    if (size == 0)
      head = tail = temp;
    else
    {
      tail->next = temp;
      temp->prev = tail;
      temp->next = head;
      head->prev = temp;
    }
    size++;
  }
  void display(Node *head)
  {
    Node *temp = head;
    while (temp->next != head)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  CircularList list1;

  list1.insertAtTail(100);
  list1.insertAtTail(200);
  list1.insertAtTail(300);
  list1.display(list1.head);

  return 0;
}