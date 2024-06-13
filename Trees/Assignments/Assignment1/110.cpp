#include <iostream>
#include <algorithm>
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
  int height(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }

  bool isBalanced(TreeNode *root)
  {
    if (root == nullptr)
      return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
      return false;
    bool left = isBalanced(root->left);
    if (!left)
      return false;
    bool right = isBalanced(root->right);
    if (!right)
      return false;
    return true;
  }
};

int main()
{
  // Create a balanced binary tree
  TreeNode *leftChild = new TreeNode(2, new TreeNode(3), new TreeNode(4));
  TreeNode *rightChild = new TreeNode(2, new TreeNode(4), new TreeNode(3));
  TreeNode *root = new TreeNode(1, leftChild, rightChild);

  Solution solution;
  bool result = solution.isBalanced(root);

  if (result)
  {
    cout << "The tree is balanced." << endl;
  }
  else
  {
    cout << "The tree is not balanced." << endl;
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
