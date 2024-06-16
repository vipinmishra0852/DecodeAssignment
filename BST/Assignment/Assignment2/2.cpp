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

class Solution
{
public:
  // Function to find the distance from the root to a given node x
  int distanceFromRoot(TreeNode *root, int x)
  {
    if (root->val == x)
      return 0;
    else if (root->val > x)
      return 1 + distanceFromRoot(root->left, x);
    else
      return 1 + distanceFromRoot(root->right, x);
  }

  // Function to find the distance between two nodes a and b
  int distance(TreeNode *root, int a, int b)
  {
    if (!root)
      return 0;
    // If both nodes are smaller than root, then LCA lies in left
    if (root->val > a && root->val > b)
      return distance(root->left, a, b);
    // If both nodes are greater than root, then LCA lies in right
    if (root->val < a && root->val < b)
      return distance(root->right, a, b);
    // If root is the LCA of a and b
    if (root->val >= a && root->val <= b)
      return distanceFromRoot(root, a) + distanceFromRoot(root, b);
    return 0;
  }
};

// Helper function to insert a new node in BST
TreeNode *insert(TreeNode *node, int val)
{
  if (node == NULL)
    return new TreeNode(val);
  if (val < node->val)
    node->left = insert(node->left, val);
  else if (val > node->val)
    node->right = insert(node->right, val);
  return node;
}

int main()
{
  // Constructing the BST
  TreeNode *root = new TreeNode(20);
  root = insert(root, 10);
  root = insert(root, 30);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 25);
  root = insert(root, 35);

  // Define the nodes to find the distance between
  int a = 5, b = 35;

  // Create Solution object and get the distance between nodes
  Solution solution;
  int result = solution.distance(root, a, b);

  // Print the result
  cout << "Distance between nodes " << a << " and " << b << " is: " << result << endl;

  // Clean up memory
  delete root->left->left;   // Node with value 5
  delete root->left->right;  // Node with value 15
  delete root->left;         // Node with value 10
  delete root->right->left;  // Node with value 25
  delete root->right->right; // Node with value 35
  delete root->right;        // Node with value 30
  delete root;               // Node with value 20

  return 0;
}
