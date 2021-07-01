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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = nullptr;
        while (head) {
            ListNode *temp = new ListNode(head->val);
            // insert in the start
            if (!newHead || temp->val < newHead->val) {
                temp->next = newHead;
                newHead = temp;
            } else {
                // Traverse to the correct position
                ListNode *q = nullptr, *p = newHead;
                // temp->val >= p->val to maintain stability
                while (p && temp->val >= p->val) {
                    q = p;
                    p = p->next;
                }
                // Insert in the middle or tail
                q->next = temp;
                temp->next = p;
            }
            head = head->next;
        }
        
        return newHead;
    }
};
