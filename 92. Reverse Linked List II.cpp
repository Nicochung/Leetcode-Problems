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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode *p = head, *q = nullptr;
        while (cnt < left) {
            q = p;
            p = p->next;
            ++cnt;
        }
        // tail and con are only set once, and be used to fix connection at the end
        ListNode *tail = p, *con = q;
        while (cnt <= right) {
            ListNode *r = p->next;
            p->next = q;
            q = p;
            p = r;
            ++cnt;
        }
        // Fix the final connection
        // if con != null, fix connection, else head = q
        if (con) {
            con->next = q;
        } else {
            head = q;
        }
        tail->next = p;
        return head;
    }
};
