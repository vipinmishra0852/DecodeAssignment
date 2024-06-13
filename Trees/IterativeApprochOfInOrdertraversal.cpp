#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
  vector<int> InorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> ans;
    TreeNode *node = root;
    while (st.size() > 0 || node)
    {
      if (node)
      {
        st.push(node);
        node = node->left;
      }
      else
      {
        TreeNode *temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        node = temp->right;
      }
    }
    return ans;
  }
};

int main()
{
  // Creating a sample tree:
  //      1
  //     / \
    //    2   3
  //   / \
    //  4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution solution;
  vector<int> result = solution.InorderTraversal(root);

  // Output the result
  cout << "Inorder Traversal: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // Clean up the allocated memory
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}
