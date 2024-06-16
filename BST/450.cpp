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
  // Helper function to find the in-order predecessor (IOP)
  TreeNode *iop(TreeNode *root)
  {
    TreeNode *pred = root->left;
    while (pred->right != nullptr)
    {
      pred = pred->right;
    }
    return pred;
  }

  // Helper function to find the in-order successor (IOS)
  TreeNode *ios(TreeNode *root)
  {
    TreeNode *succ = root->right;
    while (succ->left != nullptr)
    {
      succ = succ->left;
    }
    return succ;
  }

  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == nullptr)
      return nullptr; // Base case: if root is null, return null

    // If key is found at current root
    if (root->val == key)
    {
      // Case 1: No child nodes
      if (root->left == nullptr && root->right == nullptr)
      {
        delete root;
        return nullptr;
      }
      // Case 2: One child node
      else if (root->left == nullptr)
      {
        TreeNode *rightChild = root->right;
        delete root;
        return rightChild;
      }
      else if (root->right == nullptr)
      {
        TreeNode *leftChild = root->left;
        delete root;
        return leftChild;
      }
      // Case 3: Two child nodes
      else
      {
        // Find the in-order successor (IOS)
        TreeNode *succ = ios(root);
        // Copy the successor's value to the current root
        root->val = succ->val;
        // Delete the successor node from the right subtree
        root->right = deleteNode(root->right, succ->val);
      }
    }
    // If key is less than current root value, recursively delete from left subtree
    else if (key < root->val)
    {
      root->left = deleteNode(root->left, key);
    }
    // If key is greater than current root value, recursively delete from right subtree
    else
    {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};

// Helper function to perform in-order traversal and print the tree
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
  // Create a sample BST
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Print the original tree
  cout << "Original BST: ";
  printTree(root);
  cout << endl;

  // Example of deleting a node with key 3
  Solution solution;
  root = solution.deleteNode(root, 3);

  // Print the tree after deletion
  cout << "BST after deletion of key 3: ";
  printTree(root);
  cout << endl;

  // Clean up dynamically allocated memory (simplified approach)
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root->right->right;
  delete root;

  return 0;
}
