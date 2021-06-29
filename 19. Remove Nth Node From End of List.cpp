/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *delay = nullptr, *p = head, *q = nullptr;;
        while (p && n) {
            p = p ->next;
            --n;
        }
        // Case for removing first node
        if (!p && !n)
            return head->next;
        delay = head;
        while (p) {
            q = delay;
            delay = delay->next;
            p = p->next;
        }
        if (q && delay)
            q->next = delay->next;
        if (!q)
            return nullptr;
        return head;
    }
};
