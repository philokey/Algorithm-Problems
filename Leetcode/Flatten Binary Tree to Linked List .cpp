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
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        if (root -> left) {
            TreeNode *left = root -> left;
            TreeNode *right = root -> right;
            root -> left = NULL;
            root -> right = left;
            TreeNode *tmp = left;
            while (tmp -> right) {
                tmp = tmp -> right;
            }
            tmp -> right = right;
        }
        flatten(root -> right);
    }
};
