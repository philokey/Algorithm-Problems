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
vector<int> ret;
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        
        dfs(root -> left);
        ret.push_back(root -> val);
        dfs(root -> right);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return ret;
    }
};
