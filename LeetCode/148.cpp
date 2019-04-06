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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        head = sortList(head);
        fast = sortList(fast);
        head = merge(head, fast);
        return head;
    }
    
    ListNode* merge(ListNode *list1, ListNode *list2){
        ListNode *merged = NULL, *merged_tail = NULL;
        while(list1 != NULL && list2 != NULL){
            if(merged == NULL){
                if(list1->val < list2->val){
                    merged = list1;
                    merged_tail = list1;
                    list1 = list1->next;
                }else{
                    merged = list2;
                    merged_tail = list2;
                    list2 = list2->next;
                }
            }else{
                if(list1->val < list2->val){
                    merged_tail->next = list1;
                    merged_tail = merged_tail->next;
                    list1 = list1->next;
                }else{
                    merged_tail->next = list2;
                    merged_tail = merged_tail->next;
                    list2 = list2->next;
                }
            }
        }
        if(list1 == NULL){
            merged_tail->next = list2;
        }
        if(list2 == NULL){
            merged_tail->next = list1;
        }
        return merged;
    }
};