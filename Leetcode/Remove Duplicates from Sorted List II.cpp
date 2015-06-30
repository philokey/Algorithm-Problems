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
        ListNode *nhead, *now, *pre;
        if (head == NULL || head -> next == NULL) return head;
        nhead = new ListNode(-1);
        nhead -> next = head;
        pre = nhead, now = head;
        while (now && now -> next) {
            if (now -> val  == now -> next -> val) {
                while (now -> next && now -> val == now -> next -> val) now = now -> next;
                pre -> next = now -> next;
                now = now -> next;
            } else {
                pre = now;
                now = now -> next;
            }
        }
        return nhead -> next;
    }
};
