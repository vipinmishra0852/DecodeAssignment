#include <iostream>
#include <stack>
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
  // Function to flatten the binary tree to a linked list
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    // Initialize a stack and push the root node onto it
    stack<TreeNode *> st;
    st.push(root);

    TreeNode *prev = nullptr;

    // Process nodes in pre-order traversal
    while (!st.empty())
    {
      TreeNode *curr = st.top();
      st.pop();

      // Re-link previous node's right pointer to current node
      if (prev)
      {
        prev->right = curr;
        prev->left = nullptr;
      }

      // Push right and left children of current node to stack
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);

      // Update previous node to current node
      prev = curr;
    }
  }
};

// Function to print the flattened tree (linked list)
void printFlattenedTree(TreeNode *root)
{
  TreeNode *curr = root;
  while (curr)
  {
    cout << curr->val << " -> ";
    curr = curr->right;
  }
  cout << "NULL" << endl;
}

int main()
{
  // Construct a sample binary tree
  //       1
  //      / \
    //     2   5
  //    / \   \
    //   3   4   6
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  Solution solution;
  solution.flatten(root);

  // Print the flattened tree
  printFlattenedTree(root);

  // Clean up the dynamically allocated nodes
  TreeNode *curr = root;
  while (curr)
  {
    TreeNode *next = curr->right;
    delete curr;
    curr = next;
  }

  return 0;
}
