/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m==n) return head;
        ListNode *nhead = new ListNode(-1);
        nhead -> next = head;
        ListNode *pre = nhead;
    
        for (int i = 1; i < m; i++) {
            pre = pre -> next;
        }
    
        ListNode *tail = pre->next;
        
        for (int i = m; i < n; i++) {
            ListNode *cur = tail -> next;
            tail -> next = cur -> next;
            cur -> next = pre -> next;
            pre -> next = cur;
        }
        return nhead -> next;
    
    }

};
