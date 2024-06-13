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
int levels(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + max(levels(root->left), levels(root->right));
}
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
  // IN levelwise printing  it does not matter how you are printing i.e i mean it does not matter you are printing it by inorder,preorder,postorder
  // it will print from left to right,  here we are using preorder u can use inorder or postorder but it will give u the same result.
}
void levelOrder(Node *a)
{
  int n = levels(a);
  for (int i = 1; i <= n; i++)
  {
    displayNthLevel(a, 1, i);
    cout << endl;
  }
}
void RevdisplayNthLevel(Node *a, int curr, int l)
{

  if (curr == l)
  {
    cout << a->val << " ";
    return;
  }
  RevdisplayNthLevel(a->right, curr + 1, l);
  RevdisplayNthLevel(a->left, curr + 1, l);

  // IN levelwise printing  it does not matter how you are printing i.e i mean it does not matter you are printing it by inorder,preorder,postorder
  // it will print from left to right,  here we are using preorder u can use inorder or postorder but it will give u the same result.
}

void RevlevelOrder(Node *a)
{
  int n = levels(a);
  for (int i = 1; i <= n; i++)
  {
    RevdisplayNthLevel(a, 1, i);
    cout << endl;
  }
}
void levelOrderQueue(Node *root)
{
  queue<Node *> q;
  q.push(root);
  while (q.size() > 0)
  {
    Node *temp = q.front();
    q.pop();
    cout << temp->val << " ";
    if (temp->left != NULL)
      q.push(temp->left);
    if (temp->right != NULL)
      q.push(temp->right);
  }
  cout << endl;
}
void RevlevelOrderQueue(Node *root)
{
  queue<Node *> q;
  q.push(root);
  while (q.size() > 0)
  {
    Node *temp = q.front();
    q.pop();
    cout << temp->val << " ";
    if (temp->right != NULL)
      q.push(temp->right);
    if (temp->left != NULL)
      q.push(temp->left);
  }
  cout << endl;
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
  // int l = 3;
  // levelOrder(a);
  // cout << endl;
  RevlevelOrder(a);
  cout << endl;
  levelOrderQueue(a);
  cout << endl;
  RevlevelOrderQueue(a);
  cout << endl;
  return 0;
}