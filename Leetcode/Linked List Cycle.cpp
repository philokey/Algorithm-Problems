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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *fast, *slow;
        fast = slow = head;
        while(true) {
            if (fast -> next != NULL) {
                fast = fast->next;
            } else {
                return false;
            }
            if (fast -> next != NULL) {
                fast = fast->next;
            } else {
                return false;
            }
            slow = slow -> next;
            if (fast == slow) return true;
        }
    }
};
