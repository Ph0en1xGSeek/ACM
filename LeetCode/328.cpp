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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *one, *two, *even_head;
        one = head;
        even_head = two = head->next;
        while(one->next != nullptr && one->next->next != nullptr) {
            one->next = one->next->next;
            two->next = two->next->next;
            one = one->next;
            two = two->next;
        }
        one->next = even_head;
        return head;
    }
};