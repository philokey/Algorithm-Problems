/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *solve(ListNode *head, int cnt) {
        if(cnt <= 0) return NULL;
        int rootIndex = cnt / 2;
        ListNode *rootNode = head;
        for(int ir = 0; ir < rootIndex; ++ir) {
            rootNode = rootNode -> next;
        }
        TreeNode *root = new TreeNode(rootNode -> val);
        root -> left = solve(head,rootIndex);
        root -> right = solve(rootNode->next, cnt - rootIndex - 1);
        return root;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int nodeCount = 0;
        for(ListNode *cur = head; cur != NULL; cur = cur -> next) {
            ++nodeCount;
        }
        
        return solve(head, nodeCount);
    }
};
