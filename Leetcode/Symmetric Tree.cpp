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
    bool dfs(TreeNode *r1, TreeNode *r2) {
        if (r1 == NULL && r2 == NULL) return true;
        if (r1 == NULL || r2 == NULL) return false;
        if (r1 -> val != r2 -> val) return false;
        return dfs(r1 -> left, r2 -> right) && dfs(r1 -> right, r2 -> left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return dfs(root -> left, root -> right);
    }
};
