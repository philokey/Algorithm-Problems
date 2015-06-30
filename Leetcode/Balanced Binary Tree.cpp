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
    bool flag;
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        if (flag == 0) return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        if (abs(l - r) > 1) flag = 0;
        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode *root) {
        flag = 1;
        dfs(root);
        return flag;
    }
};
