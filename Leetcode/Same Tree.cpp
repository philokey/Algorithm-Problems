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
    void dfs(TreeNode *p, TreeNode *q) {
        if (flag == false) return;
        if (p == NULL && q == NULL) return;
        if (p == NULL || q == NULL) {
            flag =  false;
            return;
        }
        if (p -> val != q -> val) {
            flag = 0;
            return;
        }
        dfs(p -> left, q -> left);
        dfs(p -> right, q -> right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        flag = true;
        dfs(p,q);
        return flag;
    }
};
