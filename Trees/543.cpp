#include <iostream>
#include <algorithm> // for std::max

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
  int levels(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    return 1 + max(levels(root->left), levels(root->right));
  }

  void helper(TreeNode *root, int &maxDia)
  {
    if (root == NULL)
      return;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(maxDia, dia);
    helper(root->left, maxDia);
    helper(root->right, maxDia);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    int maxDia = 0;
    helper(root, maxDia);
    return maxDia;
  }
};

int main()
{
  // Create the binary tree:
  //         1
  //        / \
    //       2   3
  //      / \
    //     4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution solution;
  int diameter = solution.diameterOfBinaryTree(root);
  cout << "The diameter of the binary tree is: " << diameter << endl;

  // Clean up the allocated nodes
  delete root->left->right;
  delete root->left->left;
  delete root->right;
  delete root->left;
  delete root;

  return 0;
}
