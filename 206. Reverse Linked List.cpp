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
    // Iterative
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *q{}, *r{};
    //     while (head) {
    //         r = q;
    //         q = head;
    //         head = head->next;
    //         q->next = r;
    //     }
    //     return q;
    // }
    // Recursively
    ListNode *first{};
    ListNode* reverseList(ListNode* head) {
        helper(NULL, head);
        return first;
    }   
    void helper(ListNode *q, ListNode *p) {
        if (p) {
            helper(p, p->next);
            p->next = q;
        } else {
            first = q;
        }
    }
};
