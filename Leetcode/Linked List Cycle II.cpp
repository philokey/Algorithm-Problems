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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *fast, *slow, *meet;
        fast = slow = head;
        while(true) {
            if (fast -> next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            if (fast -> next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            slow = slow -> next;
            if (fast == slow) {
                meet = fast;
                break;
            }
        }
        slow = head;
        while (slow != meet) {
            slow = slow -> next;
            meet = meet -> next;
        }
        return meet;
    }
};
