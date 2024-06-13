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
  TreeNode *build(vector<int> &in, int inLo, int inHi, vector<int> &post, int postLo, int postHi)
  {
    if (inLo > inHi)
      return nullptr;
    TreeNode *root = new TreeNode(post[postHi]);
    if (inLo == inHi)
      return root;

    int i = inLo;
    while (i < inHi)
    {
      if (in[i] == post[postHi])
        break;
      i++;
    }

    int leftcount = i - inLo;
    int rightcount = inHi - i;

    root->left = build(in, inLo, i - 1, post, postLo, postLo + leftcount - 1);
    root->right = build(in, i + 1, inHi, post, postLo + leftcount, postHi - 1);
    return root;
  }

  TreeNode *buildTree(vector<int> &in, vector<int> &post)
  {
    int n = in.size();
    return build(in, 0, n - 1, post, 0, n - 1);
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
  // Sample inorder and postorder traversal arrays
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  Solution sol;
  TreeNode *root = sol.buildTree(inorder, postorder);

  // Print the tree in inorder to verify
  cout << "Inorder traversal of the constructed tree: ";
  printInorder(root);
  cout << endl;

  // Clean up the allocated tree nodes
  deleteTree(root);

  return 0;
}
