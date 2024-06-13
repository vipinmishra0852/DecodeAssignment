#include <iostream>

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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == NULL && q == NULL)
      return true;
    if (p == NULL || q == NULL)
      return false;
    if (p->val != q->val)
      return false;
    bool leftAns = isSameTree(p->left, q->left);
    bool rightAns = isSameTree(p->right, q->right);
    return leftAns && rightAns;
  }
};

int main()
{
  // Create first binary tree:
  //     1
  //    / \
    //   2   3
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);

  // Create second binary tree:
  //     1
  //    / \
    //   2   3
  TreeNode *q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(3);

  Solution solution;
  bool result = solution.isSameTree(p, q);
  cout << "The two binary trees are " << (result ? "the same." : "not the same.") << endl;

  // Clean up the allocated nodes
  delete p->right;
  delete p->left;
  delete p;
  delete q->right;
  delete q->left;
  delete q;

  return 0;
}
