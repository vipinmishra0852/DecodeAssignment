#include <iostream>
#include <vector>
#include <algorithm> // for max
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to compute the height of the binary tree
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    // Helper function to collect nodes at a specific level in zigzag order
    void displayNthLevel(TreeNode *a, int curr, int l, vector<int>& v) {
        if (a == NULL)
            return;
        if (curr == l) {
            v.push_back(a->val);
            return;
        }
        if (l % 2 != 0) {
            displayNthLevel(a->left, curr + 1, l, v);
            displayNthLevel(a->right, curr + 1, l, v);
        } else {
            displayNthLevel(a->right, curr + 1, l, v);
            displayNthLevel(a->left, curr + 1, l, v);
        }
    }

    // Function to collect nodes level by level in zigzag order and add to the result
    void levelorder(TreeNode *a, vector<vector<int>>& ans) {
        int n = levels(a);
        for (int i = 1; i <= n; i++) { 
            vector<int> v;
            displayNthLevel(a, 1, i, v);
            ans.push_back(v);
        }
    }

    // Main function to perform zigzag level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root, ans);
        return ans;
    }
};

int main() {
    // Creating a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Printing the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated nodes
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
