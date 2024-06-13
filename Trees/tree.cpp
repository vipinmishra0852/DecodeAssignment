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
int sum(Node *root)
{
  if (root == NULL)
    return 0;
  return root->val + sum(root->left) + sum(root->right);
}
int size(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + size(root->left) + size(root->right);
}
int maxInTree(Node *root)
{
  if (root == NULL)
    return INT_MIN;
  int lMax = maxInTree(root->left);
  int rMax = maxInTree(root->right);
  return max(root->val, max(lMax, rMax));
}
int minInTree(Node *root)
{
  if (root == NULL)
    return INT_MAX;
  int lMin = minInTree(root->left);
  int rMin = minInTree(root->right);
  return min(root->val, min(lMin, rMin));
}
int levels(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + max(levels(root->left), levels(root->right));
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
  int ans = sum(a);
  cout << ans << endl;
  cout << size(a) << endl;
  cout << maxInTree(a) << endl;
  cout << levels(a) << endl;
  cout << minInTree(a) << endl;
  cout << product(a) << endl;
  return 0;
}