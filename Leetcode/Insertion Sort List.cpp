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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *nhead = new ListNode(-111111111);
        ListNode *pre, *now, *tmp;
        while (head != NULL) {
            pre = nhead;
            now = nhead -> next;
            while (now != NULL && now -> val < head -> val) {
                pre = now;
                now = now -> next;
            }
            if (now == NULL) {
                pre -> next = head;
                head = head -> next;
                pre -> next -> next = NULL;
            } else {
                tmp = pre -> next;
                pre -> next = head;
                
                head = head -> next;
                pre -> next -> next = tmp;
            }
        }
        return nhead -> next;
    }
};