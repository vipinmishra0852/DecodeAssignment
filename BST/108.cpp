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
  // Helper function to construct a BST from sorted array
  TreeNode *helper(vector<int> &nums, int lo, int hi)
  {
    if (lo > hi)
      return nullptr;
    int mid = lo + (hi - lo) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, lo, mid - 1);
    root->right = helper(nums, mid + 1, hi);
    return root;
  }

  // Main function to convert sorted array to BST
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    if (nums.empty())
      return nullptr;
    return helper(nums, 0, nums.size() - 1);
  }
};

// Helper function to print the tree in-order
void printTree(TreeNode *root)
{
  if (root == nullptr)
    return;
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
}

int main()
{
  // Example sorted array
  vector<int> nums = {-10, -3, 0, 5, 9};

  Solution solution;
  TreeNode *root = solution.sortedArrayToBST(nums);

  // Print the tree after conversion to BST
  cout << "BST from sorted array: ";
  printTree(root);
  cout << endl;

  // Clean up the dynamically allocated nodes
  // This is a simplistic approach; in practice, you might want to implement a tree destructor to handle this
  delete root->left->left;
  delete root->left;
  delete root->right->left;
  delete root->right;
  delete root;

  return 0;
}
