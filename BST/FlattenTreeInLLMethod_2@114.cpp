#include <bits/stdc++.h>

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

    // Store left and right subtrees
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    // Set left and right of root to nullptr
    root->left = nullptr;
    root->right = nullptr;

    // Recursively flatten left and right subtrees
    flatten(left);
    flatten(right);

    // Attach the flattened left subtree to the right of root
    root->right = left;

    // Traverse to the end of the newly attached subtree
    TreeNode *temp = root;
    while (temp->right != nullptr)
    {
      temp = temp->right;
    }

    // Attach the flattened right subtree to the end of the current list
    temp->right = right;
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
