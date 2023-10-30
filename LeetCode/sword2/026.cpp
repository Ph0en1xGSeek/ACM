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
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) {
            return;
        }
        ListNode *mid = findMid(head);
        ListNode *head2 = mid -> next;
        mid -> next = nullptr;
        head2 = reverseList(head2);
        head = mergetList(head, head2);
    }

    ListNode* findMid(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *fast = head -> next;
        ListNode *slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        while (head != nullptr) {
            ListNode *nex = head -> next;
            head -> next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }

    ListNode* mergetList(ListNode *head1, ListNode *head2) {
        if (head1 == nullptr) {
            return head2;
        }
        if (head2 == nullptr) {
            return head1;
        }
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        ListNode *pre1 = nullptr;
        while (cur1 != nullptr && cur2 != nullptr) {
            ListNode *nex1 = cur1 -> next;
            ListNode *nex2 = cur2 -> next;
            cur1 -> next = cur2;
            cur2 -> next = nex1;
            pre1 = cur1;
            cur1 = nex1;
            cur2 = nex2;
        }
        if (cur2 != nullptr) {
            pre1 -> next = cur2;
        }
        return head1;
    }
};


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
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return;
        }
        ListNode *mid = findMid(head);
        ListNode *head2 = mid -> next;
        mid -> next = nullptr;
        head2 = reverseList(head2);
        mergeList(head, head2);
    }

    ListNode* findMid(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* mergeList(ListNode *head1, ListNode *head2) {
        if (head1 == nullptr) {
            return head2;
        }
        if (head2 == nullptr) {
            return head1;
        }
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        ListNode *pre = nullptr;
        while (cur1 != nullptr && cur2 != nullptr) {
            ListNode *tmp = cur1 -> next;
            cur1 -> next = cur2;
            cur2 = cur2 -> next;
            cur1 -> next -> next = tmp;
            pre = cur2;
            cur1 = tmp;
        }
        if (cur2 != nullptr) {
            pre -> next = cur2;
        }
        return head1;
    }


};