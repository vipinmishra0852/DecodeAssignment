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
  int sum = 0;

  // Helper function for reverse in-order traversal
  void inorder(TreeNode *root)
  {
    if (root == nullptr)
      return;
    inorder(root->right);
    root->val = sum + root->val;
    sum = root->val;
    inorder(root->left);
  }

  // Function to convert BST to Greater Sum Tree
  TreeNode *bstToGst(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;
    inorder(root);
    return root;
  }
};

// Helper function to print the tree in-order
void printTree(TreeNode *root)
{
  if (root == nullptr)
    return;
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
}

int main()
{
  // Construct a sample binary search tree
  //       4
  //      / \
    //     1   6
  //    / \ / \
    //   0  2 5  7
  //        \
    //         3
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(1);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(2);
  root->left->right->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  Solution solution;
  root = solution.bstToGst(root);

  // Print the tree after conversion to Greater Sum Tree
  cout << "Greater Sum Tree: ";
  printTree(root);
  cout << endl;

  // Clean up the dynamically allocated nodes
  delete root->left->left;
  delete root->left->right->right;
  delete root->left->right;
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
