#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
  // Helper function to insert a value into the BST
  void insert(TreeNode *root, int val)
  {
    if (root == nullptr)
      return;

    if (root->val > val)
    {
      if (root->left == nullptr)
      {
        root->left = new TreeNode(val);
      }
      else
      {
        insert(root->left, val);
      }
    }
    else
    {
      if (root->right == nullptr)
      {
        root->right = new TreeNode(val);
      }
      else
      {
        insert(root->right, val);
      }
    }
  }

  // Main function to insert a value into the BST
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (root == nullptr)
    {
      return new TreeNode(val);
    }
    insert(root, val);
    return root;
  }
};

// Helper function to print the BST in order
void printBST(TreeNode *root)
{
  if (root == nullptr)
    return;
  printBST(root->left);
  cout << root->val << " ";
  printBST(root->right);
}

int main()
{
  // Construct a sample binary search tree
  //       4
  //      / \
    //     2   7
  //    / \
    //   1   3
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution solution;
  int val = 5;
  root = solution.insertIntoBST(root, val);

  // Print the BST after insertion
  cout << "BST after insertion of " << val << ": ";
  printBST(root);
  cout << endl;

  // Clean up the dynamically allocated nodes
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->left;
  delete root->right;
  delete root;

  return 0;
}
