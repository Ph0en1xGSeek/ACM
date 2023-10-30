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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast != nullptr) {
            slow = slow -> next;
            if (fast -> next != nullptr) {
                fast = fast -> next;
            }
            fast = fast -> next;
        }
        return slow;
    }
};