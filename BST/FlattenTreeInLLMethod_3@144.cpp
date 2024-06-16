#include <iostream>
#include <stack>
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
  // Function to flatten the binary tree to a linked list
  void flatten(TreeNode *root)
  {
    if (root == nullptr)
      return;

    TreeNode *curr = root;
    while (curr != nullptr)
    {
      if (curr->left != nullptr)
      {
        // Save the right subtree
        TreeNode *rightSubtree = curr->right;
        // Move left subtree to the right
        curr->right = curr->left;
        curr->left = nullptr;

        // Find the rightmost node of the new right subtree
        TreeNode *pred = curr->right;
        while (pred->right != nullptr)
        {
          pred = pred->right;
        }

        // Link the original right subtree to the rightmost node
        pred->right = rightSubtree;
      }
      // Move to the next node
      curr = curr->right;
    }

    // Ensure all left pointers are set to nullptr
    curr = root;
    while (curr != nullptr)
    {
      curr->left = nullptr;
      curr = curr->right;
    }
  }
};

// Function to print the flattened tree (linked list)
void printFlattenedTree(TreeNode *root)
{
  TreeNode *curr = root;
  while (curr)
  {
    cout << curr->val << " -> ";
    curr = curr->right;
  }
  cout << "NULL" << endl;
}

int main()
{
  // Construct a sample binary tree
  //       1
  //      / \
    //     2   5
  //    / \   \
    //   3   4   6
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  Solution solution;
  solution.flatten(root);

  // Print the flattened tree
  printFlattenedTree(root);

  // Clean up the dynamically allocated nodes
  TreeNode *curr = root;
  while (curr)
  {
    TreeNode *next = curr->right;
    delete curr;
    curr = next;
  }

  return 0;
}
