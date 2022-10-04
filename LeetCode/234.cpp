/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *pre = slow->next;
        fast = slow->next->next;
        slow->next = nullptr;
        pre->next = nullptr;
        while(fast != nullptr) {
            ListNode *nex = fast->next;
            fast->next = pre;
            pre = fast;
            fast = nex;
        }
        ListNode *a = head, *b = pre;
        while(a != nullptr && b != nullptr) {
            if(a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
};