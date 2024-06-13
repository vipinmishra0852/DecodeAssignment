#include <iostream>
#include <vector>
#include <stack>
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
  vector<int> preorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> st;
    vector<int> ans;
    if (root != nullptr)
      st.push(root);

    while (!st.empty())
    {
      TreeNode *temp = st.top();
      st.pop();
      ans.push_back(temp->val);

      if (temp->right != nullptr)
        st.push(temp->right);
      if (temp->left != nullptr)
        st.push(temp->left);
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
  vector<int> result = solution.preorderTraversal(root);

  // Output the result
  cout << "Preorder Traversal: ";
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
