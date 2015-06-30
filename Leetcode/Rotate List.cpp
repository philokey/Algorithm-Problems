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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head) {
            int len = 1;
            ListNode *tail = head;
            while(tail -> next) {
                tail = tail -> next;
                ++len;
            }
            tail -> next = head;
            k %= len;
            int step = len - k;
            while (step > 0) {
                tail = tail -> next;
                --step;
            }
            head = tail -> next;
            tail -> next = NULL;
        }
        return head;
    }
};

