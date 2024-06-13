#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool check(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr)
      return false;
    return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
  }

  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
      return true;
    return check(root->left, root->right);
  }
};

int main()
{
  // Create a symmetric binary tree
  TreeNode *leftChild = new TreeNode(2, new TreeNode(3), new TreeNode(4));
  TreeNode *rightChild = new TreeNode(2, new TreeNode(4), new TreeNode(3));
  TreeNode *root = new TreeNode(1, leftChild, rightChild);

  Solution solution;
  bool result = solution.isSymmetric(root);

  if (result)
  {
    cout << "The tree is symmetric." << endl;
  }
  else
  {
    cout << "The tree is not symmetric." << endl;
  }

  // Clean up the allocated memory
  delete leftChild->left;
  delete leftChild->right;
  delete leftChild;
  delete rightChild->left;
  delete rightChild->right;
  delete rightChild;
  delete root;

  return 0;
}
