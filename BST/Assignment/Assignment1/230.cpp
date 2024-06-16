#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
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
  void inorder(TreeNode *root, vector<int> &ans)
  {
    if (root == nullptr)
      return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
  }

  int kthSmallest(TreeNode *root, int k)
  {
    vector<int> ans;
    inorder(root, ans);
    return ans[k - 1];
  }
};

// Helper function to create a BST for testing
TreeNode *createBST()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->left->left->left = new TreeNode(1);
  return root;
}

// Main function to test the solution
int main()
{
  Solution solution;
  TreeNode *root = createBST();
  int k = 3; // Example: find the 3rd smallest element

  int result = solution.kthSmallest(root, k);
  cout << "The " << k << "-th smallest element is: " << result << endl;

  // Clean up memory
  delete root->left->left->left;
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
