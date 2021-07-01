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
    // bool isPalindrome(ListNode* head) {
    //     stack<int> s1;
    //     ListNode *firstPass = head;
    //     while (firstPass) {
    //         s1.emplace(firstPass->val);
    //         firstPass = firstPass->next;
    //     }
    //     while (head) {
    //         int temp = s1.top();
    //         if (temp == head->val) {
    //             s1.pop();
    //             head = head->next;
    //         } else {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    // 1. Find the middle of the list, (if there are two middle node, find the first middle node)
    // 2. Reverse the second half
    // 3. Compare the reversed second half with the first half
    // 4. Revert the second half back to normal
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow=head ,*fast=head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now slow is the middle (first middle of the list)
        // Reverse the second half
        ListNode *rhead = reverseList(slow->next);
        ListNode *trav = head;
        bool ansFlag = true;
        
        while (rhead) {
            if (rhead->val != trav->val) {
                ansFlag = false;
                break;
            }
            rhead = rhead->next;
            trav = trav->next;
        }
        // Reverse the second half list back to original
        reverseList(slow->next);
        return ansFlag;
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode *p = head, *q=nullptr;
        while (p) {
            ListNode *temp = p->next;
            p->next = q;
            q = p;
            p = temp;
        }
        return q;
    }
};
