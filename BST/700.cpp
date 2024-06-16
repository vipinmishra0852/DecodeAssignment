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
  // Function to search a value in the BST
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == nullptr)
      return nullptr;
    else if (root->val == val)
      return root;
    else if (root->val > val)
      return searchBST(root->left, val);
    else
      return searchBST(root->right, val);
  }
};

// Helper function to print the subtree rooted at the given node
void printTree(TreeNode *root)
{
  if (root == nullptr)
    return;
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
}

int main()
{
  // Construct a sample binary search tree
  //       4
  //      / \
    //     2   7
  //    / \
    //   1   3
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution solution;
  int val = 2;
  TreeNode *result = solution.searchBST(root, val);

  if (result != nullptr)
  {
    cout << "Subtree rooted at node with value " << val << ": ";
    printTree(result);
    cout << endl;
  }
  else
  {
    cout << "Value " << val << " not found in the tree." << endl;
  }

  // Clean up the dynamically allocated nodes
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
