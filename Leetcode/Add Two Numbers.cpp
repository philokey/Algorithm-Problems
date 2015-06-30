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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head, *now, *pre;
        head = NULL;
        int val, jw = 0;
        while (l1 != NULL or l2 != NULL) {
            val = 0;
            if (l1 != NULL) {
                val += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != NULL) {
                val += l2 -> val;
                l2 = l2 -> next;
            }
            if (head == NULL) {
                head = new ListNode(0);
                now = head;
            } else {
                now = new ListNode(0);
                pre -> next = now;
            }
            pre = now;
            now -> val = (val + jw) % 10;
            jw = (val + jw) / 10;
            now -> next = NULL;
        }
        if (jw) {
            now = new ListNode(jw);
            pre -> next = now;
        }
        return head;
    }
};
