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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *pre = head;
        ListNode *now = head -> next;
        while (now != NULL) {
            if (now -> val == pre -> val) {
                pre -> next = now -> next;
                now = pre -> next;
            } else {
                pre = now;
                now = now -> next;
            }
            
        }
        return head;
    }
};
