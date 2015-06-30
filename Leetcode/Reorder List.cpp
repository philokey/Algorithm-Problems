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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)return;
        ListNode *fastp = head, *lowp = head, *tail = NULL;
        while(fastp != NULL && fastp->next != NULL) {
            tail = lowp;
            fastp = fastp->next->next;
            lowp = lowp->next;
        }
        tail->next = NULL; 
        reverseList(lowp);
        fastp = head;
        tail = NULL;
        while(fastp != NULL) {
            ListNode *tmp = lowp->next;
            lowp->next = fastp->next;
            fastp->next = lowp;
            tail = lowp;
            fastp = lowp->next;
            lowp = tmp;
        }
        if(lowp != NULL)
            tail->next = lowp;
    }
    void reverseList(ListNode* &head) {
        if(head == NULL || head->next == NULL)return;
        ListNode *pre = head, *p = pre->next;
        while(p != NULL) {
            ListNode *tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        head->next = NULL;
        head = pre;
    }
};

