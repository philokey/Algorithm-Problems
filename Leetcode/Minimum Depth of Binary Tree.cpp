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
    int ret = 0x3f3f3f3f;
    void dfs(TreeNode *root, int dep) {
        if (root == NULL) ret = min(ret,dep);
        if (dep >= ret) return;
        if (root -> left) dfs(root -> left, dep + 1);
        if (root -> right) dfs(root -> right, dep + 1);
        if (root -> left == NULL && root -> right == NULL) ret = min(ret, dep + 1);
    }
    int minDepth(TreeNode *root) {
        dfs(root,0);
        return ret;
    }
};
