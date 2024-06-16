#include <iostream>
#include <vector>

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
  TreeNode *insertIntoBST(TreeNode *root, int value)
  {
    if (root == nullptr)
    {
      return new TreeNode(value); // Create a new node if root is nullptr
    }
    if (root->val > value)
    {
      root->left = insertIntoBST(root->left, value); // Insert into the left subtree
    }
    else
    {
      root->right = insertIntoBST(root->right, value); // Insert into the right subtree
    }
    return root;
  }

  // Function to construct a BST from a preorder traversal
  TreeNode *bstFromPreorder(vector<int> &pre)
  {
    if (pre.empty())
      return nullptr; // If the input is empty, return nullptr
    TreeNode *root = new TreeNode(pre[0]);
    for (int i = 1; i < pre.size(); i++)
    {
      insertIntoBST(root, pre[i]);
    }
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
  // Example preorder traversal
  vector<int> pre = {8, 5, 1, 7, 10, 12};

  Solution solution;
  TreeNode *root = solution.bstFromPreorder(pre);

  // Print the tree after construction
  cout << "BST from preorder traversal: ";
  printTree(root);
  cout << endl;

  // Clean up the dynamically allocated nodes
  // This is a simplistic approach; in practice, you might want to implement a tree destructor to handle this
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
