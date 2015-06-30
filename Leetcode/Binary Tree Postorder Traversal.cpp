/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, vector<int> &ret) {
        if (root == NULL) return;
        solve(root -> left, ret);
        solve(root -> right, ret);
        ret.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        solve(root,ret);
        return ret;
    }
};
