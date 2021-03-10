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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr) {
            return nullptr;
        }
        ListNode *fast = pHead, *slow = pHead;
        while(fast != nullptr && slow != nullptr) {
            if(fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
            if(fast == slow) {
                break;
            }
        }
        if(fast == nullptr) {
            return nullptr;
        }
        fast = pHead;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};