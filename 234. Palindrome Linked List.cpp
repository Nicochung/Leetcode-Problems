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
    bool isPalindrome(ListNode* head) {
        stack<int> s1;
        ListNode *firstPass = head;
        while (firstPass) {
            s1.emplace(firstPass->val);
            firstPass = firstPass->next;
        }
        while (head) {
            int temp = s1.top();
            if (temp == head->val) {
                s1.pop();
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
