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
    ListNode* swapPairs(ListNode* head) {
        if (!head || head && !head->next) return head;
        // Start swapping
        ListNode *first = head, *second = head->next;
        ListNode *temp = second->next;
        second->next = first;
        // Assign first->next as recursive function
        first->next = swapPairs(temp);
        return second;
    }
    
};
