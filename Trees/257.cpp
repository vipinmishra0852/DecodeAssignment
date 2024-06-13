#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
  void helper(TreeNode *root, vector<string> &ans, string s)
  {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL)
    {
      s = s + to_string(root->val);
      ans.push_back(s);
      return;
    }
    string a = to_string(root->val);
    helper(root->left, ans, s + a + "->");
    helper(root->right, ans, s + a + "->");
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    helper(root, ans, "");
    return ans;
  }
};

int main()
{
  // Create the binary tree:
  //         1
  //        / \
    //       2   3
  //        \
    //         5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  Solution solution;
  vector<string> paths = solution.binaryTreePaths(root);
  cout << "Root-to-leaf paths:" << endl;
  for (const string &path : paths)
  {
    cout << path << endl;
  }

  // Clean up the allocated nodes
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
