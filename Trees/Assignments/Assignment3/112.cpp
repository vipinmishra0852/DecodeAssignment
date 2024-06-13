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
  bool ans = false;

  void helper(TreeNode *root, int targetSum)
  {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr)
    {
      if (root->val == targetSum)
      {
        ans = true;
      }
      return;
    }
    helper(root->left, targetSum - root->val);
    helper(root->right, targetSum - root->val);
  }

  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (root == nullptr)
      return false;
    helper(root, targetSum);
    return ans;
  }
};

int main()
{
  // Create a sample binary tree:
  //        5
  //       / \
    //      4   8
  //     /   / \
    //    11  13  4
  //   /  \      \
    //  7    2      1
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  Solution sol;
  int targetSum = 22;
  bool result = sol.hasPathSum(root, targetSum);

  // Print the result
  cout << "Has path sum " << targetSum << ": " << (result ? "Yes" : "No") << endl;

  // Clean up the allocated tree nodes
  delete root->left->left->left;
  delete root->left->left->right;
  delete root->left->left;
  delete root->left;
  delete root->right->right->right;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
