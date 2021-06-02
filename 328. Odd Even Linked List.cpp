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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode *odd_head, *odd_trav, *even_head, *even_trav;
        odd_head = odd_trav = head;
        head = head->next;
        
        if (!head) return odd_head;
        even_head = even_trav = head;
        head = head->next;
        
        bool isodd{true};
        while (head) {
            if (isodd) {
                odd_trav->next = head;
                odd_trav = odd_trav->next;
            } else {
                even_trav->next = head;
                even_trav = even_trav->next;              
            }
            isodd = !isodd;
            head = head->next;
        }
        odd_trav->next = even_head;
        even_trav->next = NULL;

        return odd_head;
    }
};
