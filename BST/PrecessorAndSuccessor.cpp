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

void levelOrderQueue(Node *root)
{
  if (!root)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
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

Node *construct(int arr[], int n)
{
  if (n == 0)
    return NULL;
  queue<Node *> q;
  Node *root = new Node(arr[0]);
  q.push(root);
  int i = 1;
  while (i < n)
  {
    Node *temp = q.front();
    q.pop();
    if (i < n && arr[i] != INT_MIN)
    {
      temp->left = new Node(arr[i]);
      q.push(temp->left);
    }
    i++;
    if (i < n && arr[i] != INT_MIN)
    {
      temp->right = new Node(arr[i]);
      q.push(temp->right);
    }
    i++;
  }
  return root;
}

void insert(Node *&root, int val)
{
  if (root == NULL)
    root = new Node(val);
  else if (root->val > val)
  {
    if (root->left == NULL)
    {
      root->left = new Node(val);
    }
    else
      insert(root->left, val);
  }
  else
  {
    if (root->right == NULL)
    {
      root->right = new Node(val);
    }
    else
      insert(root->right, val);
  }
}

Node *insertIntoBST(Node *root, int val)
{
  insert(root, val);
  return root;
}

int precessor(Node *root, int key)
{
  Node *current = root;
  Node *pred = NULL;
  while (current != NULL)
  {
    if (current->val >= key)
    {
      current = current->left;
    }
    else
    {
      pred = current;
      current = current->right;
    }
  }
  return pred ? pred->val : -1;
}

int successor(Node *root, int key)
{
  Node *current = root;
  Node *succ = NULL;
  while (current != NULL)
  {
    if (current->val <= key)
    {
      current = current->right;
    }
    else
    {
      succ = current;
      current = current->left;
    }
  }
  return succ ? succ->val : -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *root = construct(arr, n);
  levelOrderQueue(root);
  cout << "Predecessor of 6: " << precessor(root, 6) << endl;
  cout << "Successor of 6: " << successor(root, 6) << endl;
  return 0;
}
