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
    // Floyd's Cycle Detecting Algorithm
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = isLoop(head);
        if (!p || !head) return nullptr;
        while (head != p) {
            head = head->next;
            p = p->next;
        }
        return p;
    }
    // Find if the linked list form a cycle
    ListNode *isLoop(ListNode *head) {
        ListNode *fast = head;
        while (head && fast && fast->next) {
            head = head->next;
            fast = fast->next->next;
            if (head == fast)
                return fast;
        }
        return nullptr;
    }
};
