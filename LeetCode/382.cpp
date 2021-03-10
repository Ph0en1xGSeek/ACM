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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        while(head != nullptr) {
            ++len;
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r = rand() % len;
        return arr[r];
    }
private:
    int len;
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */