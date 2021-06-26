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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1,l2,0);
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2, int carry_on) {
        if (!l1 && !l2 && !carry_on) return NULL; // if both l1 and l2 is NULL;
        ListNode* new_node = new ListNode();
        if (!l1 && !l2 && carry_on) {
            new_node->val = 1;
            return new_node;
        }
        if (!l1 && l2) {
            if (l2->val + carry_on >= 10) {
                new_node->val = l2->val + carry_on - 10;
                carry_on = 1;
            } else {
                new_node->val = l2->val + carry_on;
                carry_on = 0;
            }
            new_node->next = helper(NULL, l2->next, carry_on);
            return new_node;
        }
        if (l1 && !l2) {
            if (l1->val + carry_on >= 10) {
                new_node->val = l1->val + carry_on - 10;
                carry_on = 1;

            } else {
                new_node->val = l1->val + carry_on;
                carry_on = 0;
            }
            new_node->next = helper(l1->next, NULL, carry_on);
            return new_node;
        }
        
        if (l1->val +  l2->val + carry_on >= 10) {
            new_node->val = l1->val + l2->val + carry_on - 10;
            carry_on = 1;
        } else {
            new_node->val = l1->val + l2->val + carry_on;
            carry_on = 0;
        }
        new_node->next = helper(l1->next, l2->next, carry_on);
        return new_node;
    }
};
