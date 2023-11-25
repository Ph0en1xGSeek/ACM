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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            fast = fast -> next;
            slow = slow -> next;
            if (fast != nullptr) {
                fast = fast -> next;
            }
        } while (fast != nullptr && slow != fast);
        if (fast == nullptr) {
            return nullptr;
        }
        fast = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};


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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast -> next == nullptr) {
            return nullptr;
        }
        fast = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
        
    }
};