#include <iostream>
#include <queue> // For level order traversal

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
  // Helper function to trim the BST
  TreeNode *trim(TreeNode *root, int low, int high)
  {
    if (root == nullptr)
      return nullptr; // Base case: if root is null, return null

    // Trim the left subtree
    root->left = trim(root->left, low, high);
    // Trim the right subtree
    root->right = trim(root->right, low, high);

    // Check if the current node's value is within the range
    if (root->val < low)
    {
      // If current node's value is less than low, return its right subtree (as it's trimmed out)
      return root->right;
    }
    else if (root->val > high)
    {
      // If current node's value is greater than high, return its left subtree (as it's trimmed out)
      return root->left;
    }
    else
    {
      // If current node's value is within the range, return the current node
      return root;
    }
  }

  TreeNode *trimBST(TreeNode *root, int low, int high)
  {
    // Call the helper function to trim the BST
    return trim(root, low, high);
  }
};

// Function to perform level order traversal of the tree
void levelOrder(TreeNode *root)
{
  if (root == nullptr)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    cout << node->val << " ";

    if (node->left != nullptr)
      q.push(node->left);
    if (node->right != nullptr)
      q.push(node->right);
  }
  cout << endl;
}

int main()
{
  // Example BST: [3, 0, 4, null, 2, null, null, 1]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(0);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(1);

  // Print original BST using level order traversal
  cout << "Original BST: ";
  levelOrder(root);

  Solution solution;
  int low = 1, high = 3;

  // Trim the BST to the range [low, high]
  TreeNode *trimmedBST = solution.trimBST(root, low, high);

  // Print trimmed BST using level order traversal
  cout << "Trimmed BST (range [" << low << ", " << high << "]): ";
  levelOrder(trimmedBST);

  // Clean up dynamically allocated memory
  // This is a simplified approach; in practice, you might want to implement a proper destructor
  delete root->left->right->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
