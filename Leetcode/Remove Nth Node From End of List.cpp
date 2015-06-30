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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre, *now, *p;
        p = head;
        for (int i = 0; i < n - 1; ++i) {
            p = p -> next;
        }
        pre = NULL;
        now = head;
        while (p -> next) {
            p = p -> next;
            pre = now;
            now = now -> next;
        }
        if (pre == NULL) return head -> next;
        pre -> next = now -> next;
        return head;
    }
};
