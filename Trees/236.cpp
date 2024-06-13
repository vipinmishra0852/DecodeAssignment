#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class that includes methods to check if a node exists and to find the lowest common ancestor.
class Solution
{
public:
  // Method to check if a target node exists in the tree rooted at 'root'
  bool exists(TreeNode *root, TreeNode *target)
  {
    if (root == NULL)
      return false; // If the root is NULL, the target cannot exist here
    if (root == target)
      return true; // If the root is the target, return true
    // Recursively check if the target exists in the left or right subtree
    return exists(root->left, target) || exists(root->right, target);
  }

  // Method to find the lowest common ancestor (LCA) of two nodes in the tree
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == p || root == q)
      return root; // If the root is p or q, it is the LCA

    // Check if p is in the left subtree and q is in the right subtree
    if (exists(root->left, p) && exists(root->right, q))
      return root;
    // Check if q is in the left subtree and p is in the right subtree
    if (exists(root->left, q) && exists(root->right, p))
      return root;

    // If both p and q are in the left subtree, continue searching in the left subtree
    if (exists(root->left, p) && exists(root->left, q))
      return lowestCommonAncestor(root->left, p, q);
    // Otherwise, continue searching in the right subtree
    else
      return lowestCommonAncestor(root->right, p, q);
  }
};

int main()
{
  // Create the binary tree:
  //         3
  //        / \
    //       5   1
  //      / \ / \
    //     6  2 0  8
  //       / \
    //      7   4
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  // Define the nodes to find the LCA
  TreeNode *p = root->left;               // Node with value 5
  TreeNode *q = root->left->right->right; // Node with value 4

  // Create an instance of the Solution class
  Solution solution;
  // Find the lowest common ancestor of nodes p and q
  TreeNode *lca = solution.lowestCommonAncestor(root, p, q);

  // Print the result
  if (lca != NULL)
  {
    cout << "The lowest common ancestor is: " << lca->val << endl;
  }
  else
  {
    cout << "No common ancestor found." << endl;
  }

  // Clean up the allocated nodes to avoid memory leaks
  delete root->left->right->right;
  delete root->left->right->left;
  delete root->right->right;
  delete root->right->left;
  delete root->left->right;
  delete root->left->left;
  delete root->right;
  delete root->left;
  delete root;

  return 0;
}
