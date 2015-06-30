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
    TreeNode *pre;
    TreeNode *s1, *s2;
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        dfs(root -> left);
        if (pre != NULL && pre -> val > root -> val) {
            if(s1 == NULL) {
                s1 = pre;
                s2 = root;
            }
            else s2 = root; 
        }
        pre = root;
        dfs(root -> right);
    }
    void recoverTree(TreeNode *root) {
        s1 = s2 = pre = NULL;
        dfs(root);
        swap(s1 -> val, s2 -> val);
    }
};
