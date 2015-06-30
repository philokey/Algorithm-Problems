/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        TreeLinkNode * now, *pre = NULL;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            now = q.front();
            q.pop();
            if (pre != NULL) {
                pre -> next = now;
            }
            if (now == NULL) {
                if (!q.empty()) {
                    pre = NULL;
                    q.push(NULL);
                } else {
                    break;
                }
            } else {
                pre = now;
                if (now -> left) q.push(now -> left);
                if (now -> right) q.push(now -> right);
            }
        }
    }
};
