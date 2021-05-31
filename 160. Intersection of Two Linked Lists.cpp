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
        if (!headA || !headB) return NULL;
        stack<ListNode *> s1, s2;
        ListNode *top=NULL;
        while (headA) {
            s1.emplace(headA);
            headA = headA->next;
        }
        while (headB) {
            s2.emplace(headB);
            headB = headB->next;
        }
        while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
            top = s1.top();
            s1.pop();
            s2.pop();
        }
        return top;
    }
};
