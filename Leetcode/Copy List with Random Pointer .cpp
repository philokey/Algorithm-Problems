/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *now,*tmp, *ptr;
        ptr = head;
        while (ptr) {
            tmp = ptr -> next;
            ptr -> next = new RandomListNode(ptr -> label);
            ptr -> next -> next = tmp;
            ptr = tmp;
        }
        ptr = head;
        while (ptr) {
            if (ptr -> random)
                ptr -> next -> random = ptr -> random -> next;
            ptr = ptr -> next -> next;
        }
        newHead = NULL;
        ptr = head;
        while (ptr) {
            tmp = ptr -> next -> next;
            if (newHead == NULL) {
                newHead = ptr -> next;
                now = newHead;
            } else {
                now -> next = ptr -> next;
                now = now -> next;
            }
            ptr -> next = tmp;
            ptr = tmp;
        }
        return newHead;
    }
};