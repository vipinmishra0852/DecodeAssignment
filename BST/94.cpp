#include <iostream>
#include <vector>
#include <stack>

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
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
      if (curr->left != nullptr)
      {
        TreeNode *pred = curr->left;
        while (pred->right != nullptr && pred->right != curr)
        {
          pred = pred->right;
        }
        if (pred->right == nullptr)
        {
          pred->right = curr;
          curr = curr->left;
        }
        else
        {
          pred->right = nullptr;
          ans.push_back(curr->val);
          curr = curr->right;
        }
      }
      else
      {
        ans.push_back(curr->val);
        curr = curr->right;
      }
    }

    return ans;
  }
};

// Helper function to create a binary tree for testing
TreeNode *createBinaryTree()
{
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  return root;
}

// Main function to test the solution
int main()
{
  Solution solution;
  TreeNode *root = createBinaryTree();

  // Perform inorder traversal
  vector<int> result = solution.inorderTraversal(root);

  // Print the inorder traversal result
  cout << "Inorder traversal result: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // Clean up memory
  delete root->right->left;
  delete root->right;
  delete root;

  return 0;
}
