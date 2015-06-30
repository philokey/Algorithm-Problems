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
    void dfs(TreeNode *root, int dep) {
        if (root == NULL) {
            return ret = max(ret,dep); 
        }
        dfs(root -> left, dep + 1);
        dfs(root -> right, dep + 1);
    }
    int maxDepth(TreeNode *root) {
        dfs(root,0);
        return ret;
    }
};
