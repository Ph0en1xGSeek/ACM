/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        stack<ListNode*> s;
        ListNode *cur = head;
        while(cur != nullptr) {
            s.push(cur);
            cur = cur->next;
        }
        while(!s.empty()) {
            int val = s.top()->val;
            s.pop();
            res.push_back(val);
        }
        return res;
    }
};