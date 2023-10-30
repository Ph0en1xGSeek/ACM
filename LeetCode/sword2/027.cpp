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
        ListNode *mid = findMid(head);
        ListNode *head2 = mid -> next;
        head2 = reverseList(head2);
        mid -> next = nullptr;
        while (head != nullptr && head2 != nullptr) {
            if (head -> val != head2 -> val) {
                return false;
            }
            head = head -> next;
            head2 = head2 -> next;
        }
        return true;
    }

        ListNode* findMid(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *fast = head -> next;
        ListNode *slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        while (head != nullptr) {
            ListNode *nex = head -> next;
            head -> next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }
};