/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        auto cmp = [&lists](int a, int b) {
            return lists[a] -> val > lists[b] -> val;
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < k; ++i) {
            if (lists[i] != nullptr) {
                q.push(i);
            }
        }
        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        while (!q.empty()) {
            int pos = q.top();
            q.pop();
            cur -> next = lists[pos];
            lists[pos] = lists[pos] -> next;
            cur = cur -> next;
            cur -> next = nullptr;
            if (lists[pos] != nullptr) {
                q.push(pos);
            }
        }
        return dummyHead -> next;
        
    }
};