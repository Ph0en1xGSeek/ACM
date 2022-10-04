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
    unordered_set<ListNode*> nodeSet;
    ListNode *detectCycle(ListNode *head) {
        ListNode *cur = head;
        while(cur != NULL){
            if(nodeSet.count(cur) != 0){
                break;
            }
            nodeSet.insert(cur);
            cur = cur->next;
        }
        return cur;
    }
};