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
    ListNode *insertionSortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *sortedTail = head, *cur = head->next;
        ListNode *finder = nullptr, *finder_pre = nullptr;
        while(cur != nullptr) {
            finder = head;
            finder_pre = nullptr;
            while(finder != cur && finder->val <= cur->val) {
                finder_pre = finder;
                finder = finder->next;
            }
            if(finder_pre == nullptr) {
                sortedTail->next = cur->next;
                cur->next = head;
                head = cur;
            }else if(finder != cur) {
                sortedTail->next = cur->next;
                cur->next = finder_pre->next;
                finder_pre->next = cur;
            }else {
                sortedTail = cur;
            }
            cur = sortedTail->next;
        }
        return head;
    }
};