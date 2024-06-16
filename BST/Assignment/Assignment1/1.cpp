#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  // Function to find the node with minimum value in BST
  TreeNode *findMin(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr; // Edge case: empty tree

    while (root->left != nullptr)
    {
      root = root->left; // Traverse left subtree
    }
    return root; // Return the node with minimum value
  }

  // Function to find the node with maximum value in BST
  TreeNode *findMax(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr; // Edge case: empty tree

    while (root->right != nullptr)
    {
      root = root->right; // Traverse right subtree
    }
    return root; // Return the node with maximum value
  }
};

// Helper function to create a BST for testing
TreeNode *createBST()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(10);
  return root;
}

// Main function to test the solution
int main()
{
  Solution solution;
  TreeNode *root = createBST();

  // Find minimum node
  TreeNode *minNode = solution.findMin(root);
  cout << "Minimum node value: " << minNode->val << endl;

  // Find maximum node
  TreeNode *maxNode = solution.findMax(root);
  cout << "Maximum node value: " << maxNode->val << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
