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
    int numComponents(ListNode* head, vector<int>& G) {
    	unordered_set<int> st;
        for(int item: G) {
            st.insert(item);
        }
        int ans = 0;
        ListNode *cur = head;
        while(cur != nullptr) {
            if(st.find(cur->val) != st.end() && ((cur->next == nullptr) || st.find(cur->next->val) == st.end())) {
                ++ans;
            }
            cur = cur->next;
        }
        return ans;
    }
};
