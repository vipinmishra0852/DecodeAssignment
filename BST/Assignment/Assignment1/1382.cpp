#include <iostream>
#include <vector>
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
  void inorder(TreeNode *root, vector<TreeNode *> &v)
  {
    if (root == nullptr)
      return;
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
  }

  TreeNode *solve(int low, int high, vector<TreeNode *> &v)
  {
    if (low > high)
      return nullptr;
    int mid = (low + high) / 2;
    v[mid]->left = solve(low, mid - 1, v);
    v[mid]->right = solve(mid + 1, high, v);
    return v[mid];
  }

  TreeNode *balanceBST(TreeNode *root)
  {
    vector<TreeNode *> v;
    inorder(root, v);
    return solve(0, v.size() - 1, v);
  }
};

// Helper function to create a BST for testing
TreeNode *createBST()
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);
  root->right->right->right->right = new TreeNode(5);
  return root;
}

// Helper function to print inorder traversal of a BST
void printInorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

// Main function to test the solution
int main()
{
  Solution solution;
  TreeNode *root = createBST();
  cout << "Original BST inorder: ";
  printInorder(root);
  cout << endl;

  TreeNode *balancedRoot = solution.balanceBST(root);
  cout << "Balanced BST inorder: ";
  printInorder(balancedRoot);
  cout << endl;

  // Clean up memory
  delete root->right->right->right->right;
  delete root->right->right->right;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
