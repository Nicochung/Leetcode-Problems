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
  // Reuse mergeTwoLists to perform mergeKLists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        for (int i = 1; i < lists.size(); ++i) {
            lists[0] = this->mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = nullptr, *trav = nullptr;
        if (l1->val > l2-> val) {
            head = l2;
            l2 = l2->next;
        } else {
            head = l1;
            l1 = l1->next;
        }
        trav = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                trav->next = l2;
                l2 = l2->next;
            } else {
                trav->next = l1;
                l1 = l1->next;
            }
            trav = trav->next;
        }   
        if (l1)
            trav->next = l1;
        if (l2)
            trav->next = l2;
        return head;
    }
    // Try to implement independently
     ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *trav = nullptr;
        int minIndex = -1;
        int minVal = INT_MAX;
        // Decide the head out of all the lists
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] && lists[i]->val < minVal) {
                minIndex = i;
                minVal = lists[i]->val;
            }
        }
        if (minIndex != -1) {
            head = lists[minIndex];
            trav = head;
            lists[minIndex] = lists[minIndex]->next;
        }

        // While all the lists[i] is still a valid pointer
        while (minIndex != -1) {
            minIndex = -1;
            minVal = INT_MAX;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < minVal) {
                    minIndex = i;
                    minVal = lists[i]->val;
                }
            }
            if (minIndex != -1) {
                trav->next = lists[minIndex];
                trav = trav->next;
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        return head;
    }
};
