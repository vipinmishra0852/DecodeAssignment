#include <iostream>
#include <algorithm> // for max
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
  // Helper function to compute height and update diameter
  int helper(TreeNode *root, int &maxDia)
  {
    if (root == NULL)
      return 0;

    int leftHeight = helper(root->left, maxDia);
    int rightHeight = helper(root->right, maxDia);

    // Update the diameter if the path through root is larger
    maxDia = max(maxDia, leftHeight + rightHeight);

    // Return the height of the tree rooted at this node
    return 1 + max(leftHeight, rightHeight);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    int maxDia = 0;
    helper(root, maxDia);
    return maxDia;
  }
};

int main()
{
  // Creating a simple binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution sol;
  int result = sol.diameterOfBinaryTree(root);

  // Printing the result
  cout << "Diameter of the binary tree: " << result << endl;

  // Clean up dynamically allocated nodes
  delete root->left->right;
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
