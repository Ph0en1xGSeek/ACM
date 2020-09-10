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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        if(head == nullptr) {
            return ans;
        }
        dfs(head, ans);
        return ans;
    }

    void dfs(ListNode *cur, vector<int> &res) {
        if(cur->next != nullptr) {
            dfs(cur->next, res);
        }
        res.push_back(cur->val);
    }
};