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

Node *construct(int arr[], int n)
{
  queue<Node *> q;
  Node *root = new Node(arr[0]);
  q.push(root);
  int i = 1;
  int j = 2;
  while (q.size() > 0 && i < n)
  {
    Node *temp = q.front();
    q.pop();
    Node *l;
    Node *r;
    if (arr[i] != INT_MIN)
      l = new Node(arr[i]);
    else
      l = NULL;
    if (j != n && arr[j] != INT_MIN)
      r = new Node(arr[j]);
    else
      r = NULL;
    temp->left = l;
    temp->right = r;
    if (l != NULL)
      q.push(l);
    if (r != NULL)
      q.push(r);
    i += 2;
    j += 2;
  }
  return root;
}

void leftboundaryTraversal(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL)
    return;
  cout << root->val << " ";
  leftboundaryTraversal(root->left);
  if (!root->left)
    leftboundaryTraversal(root->right);
}
void leafboundaryTraversal(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL)
  {
    cout << root->val << " ";
  }
  leafboundaryTraversal(root->left);
  leafboundaryTraversal(root->right);
}
void rightboundaryTraversal(Node *root)
{
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL)
    return;

  rightboundaryTraversal(root->right);
  if (!root->right)
    rightboundaryTraversal(root->left);
  cout << root->val << " ";
}
void boundary(Node *temp)
{
  leftboundaryTraversal(temp);
  leafboundaryTraversal(temp);
  rightboundaryTraversal(temp->right);
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *temp = construct(arr, n);
  // levelOrder(temp);
  boundary(temp);

  return 0;
}