/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if (!head) return false;
//         ListNode* fast = head->next;
//         while (fast) {
//             if (fast == head)
//                 return true;
//             head = head->next;
//             fast = fast->next;
//             if (fast)
//                 fast = fast->next;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow{head}, *fast{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }         
        return false;
    }
};
