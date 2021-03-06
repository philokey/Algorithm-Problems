//层序遍历，在每层尾部加一个NULL标记，可以不要多余的空间去记录
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        vector<int> level;
        if (root == NULL) return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            if (u != NULL) {
                level.push_back(u -> val);
                if (u -> left) q.push(u -> left);
                if (u -> right) q.push(u -> right);
            } else {
                ret.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }
        return ret;
    }
};
