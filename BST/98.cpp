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
  // Helper function for in-order traversal
  void inorder(TreeNode *root, vector<int> &ans)
  {
    if (root == nullptr)
      return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
  }

  // Function to check if a binary tree is a valid BST
  bool isValidBST(TreeNode *root)
  {
    vector<int> ans;
    inorder(root, ans);
    for (int i = 1; i < ans.size(); i++)
    {
      if (ans[i - 1] >= ans[i])
        return false;
    }
    return true;
  }
};

// Helper function to print a vector
void printVector(const vector<int> &vec)
{
  for (int val : vec)
  {
    cout << val << " ";
  }
  cout << endl;
}

int main()
{
  // Construct a sample binary search tree
  //       4
  //      / \
    //     2   5
  //    / \
    //   1   3
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution solution;

  // Check if the binary tree is a valid BST
  bool isValid = solution.isValidBST(root);

  if (isValid)
  {
    cout << "The binary tree is a valid BST." << endl;
  }
  else
  {
    cout << "The binary tree is not a valid BST." << endl;
  }

  // Clean up the dynamically allocated nodes
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
