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
  int ans = 0;

  // Helper function to check if a subtree lies within the given range
  bool helper(TreeNode *root, int low, int high)
  {
    if (root == NULL)
      return true;

    bool l = helper(root->left, low, high);
    bool r = helper(root->right, low, high);

    if (l && r && low <= root->val && root->val <= high)
    {
      ans++;
      return true;
    }

    return false;
  }

  // Main function to count subtrees within the range
  int getCount(TreeNode *root, int low, int high)
  {
    ans = 0; // Reset the count
    helper(root, low, high);
    return ans;
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
  TreeNode *root = new TreeNode(10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 18);

  // Define the range
  int low = 5, high = 15;

  // Create Solution object and get the count of subtrees
  Solution solution;
  int result = solution.getCount(root, low, high);

  // Print the result
  cout << "Number of subtrees with nodes in range [" << low << ", " << high << "]: " << result << endl;

  // Clean up memory
  delete root->left->left;   // Node with value 3
  delete root->left->right;  // Node with value 7
  delete root->left;         // Node with value 5
  delete root->right->left;  // Node with value 12
  delete root->right->right; // Node with value 18
  delete root->right;        // Node with value 15
  delete root;               // Node with value 10

  return 0;
}
