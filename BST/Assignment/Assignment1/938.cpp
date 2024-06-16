#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void inorder(TreeNode *root, vector<int> &v)
  {
    if (root == nullptr)
      return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
  }

  int rangeSumBST(TreeNode *root, int low, int high)
  {
    vector<int> v;
    inorder(root, v);
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
      if (v[i] >= low && v[i] <= high)
      {
        sum += v[i];
      }
    }
    return sum;
  }
};

// Helper function to create a BST for testing
TreeNode *createBST()
{
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->right->right = new TreeNode(18);
  return root;
}

// Main function to test the solution
int main()
{
  Solution solution;
  TreeNode *root = createBST();
  int low = 7;
  int high = 15;

  int result = solution.rangeSumBST(root, low, high);
  cout << "Sum of nodes in range [" << low << ", " << high << "]: " << result << endl;

  // Clean up memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
