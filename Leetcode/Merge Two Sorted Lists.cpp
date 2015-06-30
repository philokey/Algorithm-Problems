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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-10000000);
        ListNode *now = head;
        int val;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                if (l1 -> val < l2 -> val) {
                    now -> next = l1;
                    l1 = l1 -> next;
                } else {
                    now -> next = l2;
                    l2 = l2 -> next;
                }
            }
            else if (l1 != NULL) {
                now -> next = l1;
                l1 = l1 -> next;
            } else {
                now -> next = l2;
                l2 = l2 -> next;
            }
            now = now -> next;
        }
        return head -> next;
    }
};
