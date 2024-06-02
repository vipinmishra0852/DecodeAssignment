#include <bits/stdc++.h>
using namespace std;

class Node // User defined data structure
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

class LinkedList
{
public:
  Node *head;
  Node *tail;
  int size;
  LinkedList()
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
      Node *temp = head;
      int count = 0;
      while (idx != count)
      {
        temp = temp->next;
        count++;
      }
      return temp->val;
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
      delete head;
      head = tail = nullptr;
      size--;
      return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
      temp = temp->next;
    }
    tail = temp;
    temp->next = NULL;
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
      size--;
    }
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
  void reverse_display(Node *temp)
  {
    if (temp == NULL)
      return;
    else
    {
      reverse_display(temp->next);
      cout << temp->val << " ";
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
};

int main()
{
  LinkedList l1;
  l1.insertAtTail(10);
  l1.insertAtTail(20);
  l1.insertAtTail(30);
  l1.display();
  l1.reverse_display(l1.head);

  cout << endl;
  cout << "size " << l1.size << endl;
  l1.insertAtHead(80);
  l1.display();
  l1.reverse_display(l1.head);
  cout << endl;
  cout << "size " << l1.size << endl;
  l1.insertAtTail(40);

  l1.display();
  l1.reverse_display(l1.head);
  cout << endl;
  cout << "size " << l1.size << endl;
  l1.insert_at_idx(4, 15);
  l1.display();
  l1.reverse_display(l1.head);
  cout << endl;
  cout << "size " << l1.size << endl;
  int ans = l1.get_element(4);
  cout << ans << endl;
  l1.deleteatHead();
  l1.display();
  cout << "size " << l1.size << endl;
  l1.deleteatTail();
  l1.display();
  cout << "size " << l1.size << endl;
  l1.deleteAtIndex(2);
  l1.display();
  cout << "size " << l1.size << endl;
  l1.deleteNode(l1.head, 20);
  l1.display();
  cout << "size " << l1.size << endl;
  return 0;
}