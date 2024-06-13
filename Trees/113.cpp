#include <iostream>
#include <vector>
#include <algorithm> // Include this for std::max

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
  void helper(TreeNode *root, vector<int> v, vector<vector<int>> &ans, int sum)
  {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr)
    {
      if (root->val == sum)
      {
        v.push_back(root->val);
        ans.push_back(v);
      }
      return;
    }
    v.push_back(root->val);
    helper(root->left, v, ans, sum - root->val);
    helper(root->right, v, ans, sum - root->val);
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> ans;
    vector<int> v;
    helper(root, v, ans, targetSum);
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
  //   /  \    / \
    //  7    2  5   1
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(1);

  Solution sol;
  int targetSum = 22;
  vector<vector<int>> result = sol.pathSum(root, targetSum);

  // Print the paths that sum to targetSum
  cout << "Paths that sum to " << targetSum << ":" << endl;
  for (const auto &path : result)
  {
    for (int val : path)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Clean up the allocated tree nodes
  delete root->left->left->left;
  delete root->left->left->right;
  delete root->left->left;
  delete root->left;
  delete root->right->right->left;
  delete root->right->right->right;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
