#include <iostream>
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
  TreeNode *dfs(vector<int> &preorder, int prestart, int preend, vector<int> &postorder, int poststart, int postend)
  {
    if (prestart > preend)
      return nullptr;
    if (poststart > postend)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[prestart]);
    if (prestart == preend)
      return root;

    int postindex = poststart;
    while (postorder[postindex] != preorder[prestart + 1])
    {
      postindex++;
    }

    int len = postindex - poststart + 1;

    root->left = dfs(preorder, prestart + 1, prestart + len, postorder, poststart, postindex);
    root->right = dfs(preorder, prestart + len + 1, preend, postorder, postindex + 1, postend - 1);

    return root;
  }

  TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
  {
    return dfs(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
};

// Helper function to print the tree in inorder traversal
void printInorder(TreeNode *root)
{
  if (root == nullptr)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

// Helper function to clean up the tree nodes
void deleteTree(TreeNode *root)
{
  if (root == nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main()
{
  // Sample preorder and postorder traversal arrays
  vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

  Solution sol;
  TreeNode *root = sol.constructFromPrePost(preorder, postorder);

  // Print the tree in inorder to verify
  cout << "Inorder traversal of the constructed tree: ";
  printInorder(root);
  cout << endl;

  // Clean up the allocated tree nodes
  deleteTree(root);

  return 0;
}
