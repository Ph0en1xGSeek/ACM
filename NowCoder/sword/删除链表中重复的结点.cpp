/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }
        ListNode *cur = pHead, *nex = nullptr, *pre = nullptr, *tmp = nullptr;
        while(cur != nullptr && cur->next != nullptr) {
            nex = cur->next;
            while(nex != nullptr && nex->val == cur->val) {
                nex = nex->next;
            }
            if(nex != cur->next) {
                if(pre != nullptr) {
                    pre->next = nex;
                }else {
                    pHead = nex;
                }
                while(cur != nex) {
                    tmp = cur->next;
                    delete cur;
                    cur = tmp;
                }
            }else {
                pre = cur;
                cur = cur->next;
            }
        }
        return pHead;
    }
};