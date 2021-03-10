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
    ListNode *partition(ListNode *head, int x) {
        if(head == nullptr) {
            return head;
        }
        ListNode *less = nullptr, *less_tail = nullptr;
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            if(cur->val < x) {
                if(less == nullptr) {
                    less = less_tail = cur;
                    if(pre == nullptr) {
                        head = head->next;
                    }else {
                        pre->next = cur->next;
                    }
                    cur = cur->next;
                    less_tail->next = nullptr;
                }else {
                    less_tail->next = cur;
                    less_tail = less_tail->next;
                    if(pre == nullptr) {
                        head = head->next;
                    }else {
                        pre->next = cur->next;
                    }
                    cur = cur->next;
                    less_tail->next = nullptr;
                }
            }else {
                pre = cur;
                cur = cur->next;
            }
        }
        if(less == nullptr) {
            return head;
        }else {
            less_tail->next = head;
            return less;
        }
    }
};