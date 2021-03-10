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
    
    int dfs(ListNode *c1, ListNode *c2, int cnt1, int cnt2) {
        int remain = 0;
        if(cnt1 == 0) {
            return 0;
        }else if(cnt1 > cnt2) {
            remain = dfs(c1->next, c2, cnt1-1, cnt2);
            c1->val += remain;
            
        }else if(cnt1 == cnt2) {
            remain = dfs(c1->next, c2->next, cnt1-1, cnt2-1);
            c1->val += remain + c2->val;
        }
        remain = (c1->val) / 10;
        c1->val %= 10;
        return remain;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1 = 0, cnt2 = 0;
        ListNode *cur = l1;
        while(cur != nullptr) {
            ++cnt1;
            cur = cur->next;
        }
        cur = l2;
        while(cur != nullptr) {
            ++cnt2;
            cur = cur->next;
        }
        if(cnt1 < cnt2) {
            swap(l1, l2);
            swap(cnt1, cnt2);
        }
        int remain = dfs(l1, l2, cnt1, cnt2);
        if(remain != 0) {
            ListNode *newNode = new ListNode(remain);
            newNode->next = l1;
            l1 = newNode;
        }
        return l1;
    }
};