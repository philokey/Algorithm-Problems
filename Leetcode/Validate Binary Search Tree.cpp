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
    vector<int> mid;
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        dfs(root -> left);
        mid.push_back(root -> val);
        dfs(root -> right);
    }
    bool isValidBST(TreeNode *root) {
        dfs(root);
        bool ret = true;
        int n = mid.size();
        for (int i = 0; i < n - 1; ++i) {
            if (mid[i] >= mid[i + 1]) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};
