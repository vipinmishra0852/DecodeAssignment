#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *left;
  Node *right;
  int val;

  Node(int val)
  {
    this->left = NULL;
    this->right = NULL;
    this->val = val;
  }
};

void displayNthLevel(Node *a, int curr, int l)
{
  if (a == NULL)
    return;
  if (curr == l)
  {
    cout << a->val << " ";
  }
  displayNthLevel(a->left, curr + 1, l);
  displayNthLevel(a->right, curr + 1, l);
}

int main()
{

  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  Node *f = new Node(6);
  Node *g = new Node(7);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  int l = 3;
  displayNthLevel(a, 1, l);
  return 0;
}