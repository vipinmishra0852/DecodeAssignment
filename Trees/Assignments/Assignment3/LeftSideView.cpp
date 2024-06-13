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
  int levels(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int left = levels(root->left);
    int right = levels(root->right);
    return 1 + std::max(left, right);
  }

  void nthLevel(TreeNode *root, int curr, int level, vector<int> &ans)
  {
    if (root == nullptr)
      return;
    if (curr == level)
    {
      ans[curr] = root->val;
    }
    nthLevel(root->right, curr + 1, level, ans);
    nthLevel(root->left, curr + 1, level, ans);
  }

  void levelOrder(TreeNode *root, vector<int> &ans)
  {
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
      nthLevel(root, 0, i, ans);
    }
  }
  void preOrder(TreeNode *root, int level, vector<int> &ans)
  {
    if (root == NULL)
      return;
    ans[level] = root->val;

    preOrder(root->right, level + 1, ans);
    preOrder(root->left, level + 1, ans);
  }

  vector<int> rightSideView(TreeNode *root)
  {
    int height = levels(root);
    vector<int> ans(height, 0);
    // levelOrder(root, ans); approach 1
    preOrder(root, 0, ans);
    return ans;
  }
};

int main()
{
  // Create a sample binary tree:
  //        1
  //       / \
    //      2   3
  //       \   \
    //        5   4
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  Solution sol;
  vector<int> result = sol.rightSideView(root);

  // Print the right-side view of the tree
  cout << "Left-side view of the tree: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // Clean up the allocated tree nodes
  delete root->left->right;
  delete root->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
