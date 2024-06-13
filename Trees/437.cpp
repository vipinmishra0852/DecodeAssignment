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
  void helper(TreeNode *root, long long sum, int &count)
  {
    if (root == nullptr)
      return;
    if ((long long)(root->val) == sum)
    {
      count++;
    }
    helper(root->left, sum - (long long)(root->val), count);
    helper(root->right, sum - (long long)(root->val), count);
  }

  int pathSum(TreeNode *root, int targetSum)
  {
    if (root == nullptr)
      return 0;
    int count = 0;
    helper(root, (long long)targetSum, count);
    count += (pathSum(root->left, targetSum) + pathSum(root->right, targetSum));
    return count;
  }
};

int main()
{
  // Create a sample binary tree:
  //        10
  //       /  \
    //      5   -3
  //     / \    \
    //    3   2   11
  //   / \   \
    //  3  -2   1
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(-3);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(2);
  root->right->right = new TreeNode(11);
  root->left->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(-2);
  root->left->right->right = new TreeNode(1);

  Solution sol;
  int targetSum = 8;
  int result = sol.pathSum(root, targetSum);

  // Print the result
  cout << "Number of paths that sum to " << targetSum << ": " << result << endl;

  // Clean up the allocated tree nodes
  delete root->left->left->left;
  delete root->left->left->right;
  delete root->left->left;
  delete root->left->right->right;
  delete root->left->right;
  delete root->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
