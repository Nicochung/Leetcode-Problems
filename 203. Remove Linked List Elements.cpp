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
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         // Empty List
//         if (!head) return nullptr;
//         ListNode *p = head, *q = nullptr;
//         while (p) {
//             if (p->val == val && !q) {
//                 ListNode *temp = p;
//                 p = p->next;
//                 head = p;
//                 delete temp;
//             } else if (p->val == val && q){
//                 ListNode *temp = p;
//                 p = p->next;
//                 q->next = p;
//                 delete temp;
//             } else {
//                 q = p;
//                 p = p->next;
//             }
//         }
//         return head;
//     }
// };

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev{nullptr}, *trav{nullptr};
        if (!head) return nullptr;
        // handle target val as first element
        while (!prev && head) {
            if (head->val == val) {
                head = head->next;
            } else {
                trav = head->next;
                prev = head;
            }
        }
        
        while (trav) {
            if (trav->val == val) {
                ListNode *temp = trav;
                trav = trav->next;
                prev->next = trav;
                delete temp;
            } else {
                prev = trav;
                trav = trav->next;
            }
        }
        return head;
    }
};
