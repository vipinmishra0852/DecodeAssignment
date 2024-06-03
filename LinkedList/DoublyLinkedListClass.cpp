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

class DLL
{
public:
  Node *head;
  Node *tail;
  int size;
  DLL()
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
      tail = temp;
    }
    size++;
  }

  void insertAtHead(int val)
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

  void insert_at_idx(int idx, int val)
  {
    if (idx < 0 && idx > size)
      cout << "Invalid Index" << endl;
    else if (idx == 0)
      insertAtHead(val);
    else if (idx == size)
      insertAtTail(val);
    else
    {
      Node *t = new Node(val);
      Node *temp = head;
      for (int i = 1; i <= idx - 1; i++)
      {
        temp = temp->next;
      }
      t->next = temp->next;
      temp->next = t;
      t->prev = temp;
      t->next->prev = t;
      size++;
    }
  }
  int get_element(int idx)
  {
    if (idx < 0 || idx >= size)
    {
      cout << "Invalid Index" << endl;
      return -1;
    }
    else if (idx == 0)
    {
      return head->val;
    }
    else if (idx == size - 1)
    {
      return tail->val;
    }
    else
    {
      int count;
      if (idx < size / 2)
      {
        Node *temp = head;
        count = 0;
        while (idx != count)
        {
          temp = temp->next;
          count++;
        }
        return temp->val;
      }
      else
      {
        count = size - 1;
        Node *temp = tail;
        while (idx != count)
        {
          temp = temp->prev;
          count--;
        }
        return temp->val;
      }
    }
  }

  void deleteatHead()
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
  void deleteatTail()
  {

    if (size == 0)
    {
      cout << "List is empty";
      return;
    }
    if (size == 1)
    {
      deleteatHead();
      return;
    }
    Node *temp = tail->prev;
    temp->next = NULL;
    tail = temp;

    size--;
  }

  void deleteAtIndex(int idx)
  {
    if (size == 0)
    {
      cout << "List is empty" << endl;
      return;
    }
    else if (idx < 0 || idx >= size)
    {
      cout << "Invalid Index" << endl;
      return;
    }
    else if (idx == 0)
      deleteatHead();
    else if (idx == size - 1)
      deleteatTail();
    else
    {
      Node *temp = head;
      for (int i = 1; i <= idx - 1; i++)
      {
        temp = temp->next;
      }
      temp->next = temp->next->next;
      temp->next->prev = temp;
      size--;
    }
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

  void display(Node *head)
  {
    while (head)
    {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }

  void displayRev(Node *tail)
  {
    while (tail)
    {
      cout << tail->val << " ";
      tail = tail->prev;
    }
    cout << endl;
  }
};

int main()

{
  DLL d1;
  d1.insertAtHead(100);
  d1.insertAtHead(200);
  d1.insertAtHead(300);
  d1.display(d1.head);
  d1.insertAtTail(400);
  d1.insertAtTail(500);
  d1.display(d1.head);
  d1.insert_at_idx(2, 10);
  d1.insert_at_idx(3, 30);
  d1.display(d1.head);
  cout << "size " << d1.size << endl;
  d1.deleteatHead();
  d1.display(d1.head);
  d1.deleteatTail();
  d1.display(d1.head);
  d1.deleteAtIndex(2);
  d1.display(d1.head);
  d1.displayRev(d1.tail);
  cout << "size " << d1.size << endl;
  cout << d1.get_element(2) << endl;
  cout << d1.get_element(1) << endl;
  return 0;
}