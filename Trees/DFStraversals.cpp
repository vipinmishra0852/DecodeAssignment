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
void preorder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
void Inorder(Node *root)
{
  if (root == NULL)
    return;

  Inorder(root->left);
  cout << root->val << " ";
  Inorder(root->right);
}
void postorder(Node *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
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
  // Node *h = new Node(8);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  // g->left = h;
  cout << " PreOrder ";
  preorder(a);
  cout << endl;
  cout << "Inorder ";
  Inorder(a);
  cout << endl;
  cout << "PostOrder ";
  postorder(a);
  cout << endl;
  return 0;
}