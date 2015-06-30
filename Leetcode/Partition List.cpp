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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return head;
        ListNode *now ,*l1, *l2, *nl1, *nl2;
        l1 = new ListNode(-1);
        l2 = new ListNode(-1);
        now = head;
        nl1 = l1, nl2 = l2;
        now = head;
        int cnt = 0;
        while (now) {
            if (now -> val < x) {
                nl1 -> next = now;
                nl1 = nl1 -> next;
            } else {
                nl2 -> next = now;
                nl2 = nl2 -> next;
            }
            now = now -> next;
        }
        if (l2 -> next) nl1 -> next = l2 -> next;
        nl2 -> next = NULL;
        return l1 -> next;
    }
};
