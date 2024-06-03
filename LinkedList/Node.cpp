#include <bits/stdc++.h>
using namespace std;

class Node
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

void display(Node *head)
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

int size_of_ll(Node *head)
{
  int n = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    n++;
    temp = temp->next;
  }
  return n;
}

int main()
{
  Node a(10);

  Node b(20);

  Node c(30);
  Node d(40);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  display(&a);
  reverse_display(&a);
  int size = size_of_ll(&a);
  cout << endl;
  cout << size << endl;

  return 0;
}