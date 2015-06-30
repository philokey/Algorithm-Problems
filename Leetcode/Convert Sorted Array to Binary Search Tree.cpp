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
    TreeNode *solve(vector<int> &num, int l, int r) {
        if (l > r) return NULL;
        if (l == r) {
            return new TreeNode(num[l]);
        }
        int m = (l + r) / 2;
        TreeNode *root = new TreeNode(num[m]);
        root -> left = solve(num, l, m - 1);
        root -> right = solve(num, m + 1, r);
        return root;
        
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return solve(num, 0, num.size() - 1);
        
    }
};
