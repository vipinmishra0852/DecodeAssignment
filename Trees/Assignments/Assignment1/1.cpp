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
void display(Node *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  display(root->left);
  display(root->right);
}
int product(Node *root)
{
  if (root == NULL)
    return 1;
  int c = product(root->left);
  int d = product(root->right);
  return root->val * c * d;
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
  Node *h = new Node(8);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  g->left = h;
  display(a);
  cout << endl;
  cout << product(a) << endl;
  return 0;
}