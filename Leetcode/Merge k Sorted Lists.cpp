//优先队列优化，选出最小值

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n == 0) return NULL;

        ListNode *head = NULL, *cur = NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for (int i = 0; i < n; ++i) {
            if (lists[i] != NULL) q.push(lists[i]);
        }
        while (!q.empty()) {
            ListNode *tp = q.top();
            q.pop();
            if (tp -> next != NULL) {
                q.push(tp -> next);
            }
            if (head == NULL) {
                head = tp;
                cur = head;
            } else {
                cur -> next = tp;
                cur = cur -> next;
            }
        }
        return head;

    }
private:
    struct cmp {
        bool operator () (ListNode *a, ListNode *b) {
            return a -> val > b -> val;
        }
    };
};
