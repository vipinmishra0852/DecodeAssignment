#include <iostream>

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
  // Helper function to check if a target node exists in the tree
  bool exists(TreeNode *root, TreeNode *target)
  {
    if (root == nullptr)
      return false;
    if (root->val == target->val)
      return true;
    if (root->val < target->val)
      return exists(root->right, target);
    return exists(root->left, target);
  }

  // Function to find the lowest common ancestor of two nodes
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || root == p || root == q)
      return root;

    bool pOnLeft = exists(root->left, p);
    bool qOnLeft = exists(root->left, q);

    if (pOnLeft != qOnLeft)
      return root; // p and q are on different sides

    TreeNode *childSide = pOnLeft ? root->left : root->right;
    return lowestCommonAncestor(childSide, p, q);
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
  // Construct a sample binary search tree
  //       6
  //      / \
    //     2   8
  //    / \ / \
    //   0  4 7  9
  //     / \
    //    3   5
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  Solution solution;
  TreeNode *p = root->left;  // Node with value 2
  TreeNode *q = root->right; // Node with value 8

  TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
  if (lca != nullptr)
  {
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;
  }
  else
  {
    cout << "Lowest Common Ancestor not found." << endl;
  }

  // Clean up the dynamically allocated nodes
  delete root->left->right->left;
  delete root->left->right->right;
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->left;
  delete root->right->right;
  delete root->right;
  delete root;

  return 0;
}
