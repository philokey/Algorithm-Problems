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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0, lb = 0;
        ListNode *ha, *hb;
        ha = headA;
        hb = headB;
        while (ha) {
            ha = ha -> next;
            ++la;
        }
        while (hb) {
            hb = hb -> next;
            ++lb;
        }
        ha = headA;
        hb = headB;
        int del = abs(la - lb);
        if (la > lb) {
            while (del--) ha = ha -> next;
        } else if(la < lb) {
            while (del--) hb = hb -> next;
        }
        for (int i = 0; i < min(la, lb); ++i) {
            if (ha == hb) return ha;
            ha = ha -> next;
            hb = hb -> next;
        }
        return NULL;
    }
};
