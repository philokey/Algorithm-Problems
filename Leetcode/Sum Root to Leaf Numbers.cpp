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
    int ret = 0;
    void dfs(TreeNode* root, int sum) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            if (root == NULL)
                ret += sum;
            else ret += sum*10+root->val;
            return;
        } 
        if (root->left)
            dfs(root->left, sum*10+root->val);
        if (root->right)
            dfs(root->right, sum*10+root->val);
    }
    int sumNumbers(TreeNode *root) {
        dfs(root, 0);
        return ret;
    }
};
