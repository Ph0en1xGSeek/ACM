/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // duplicate链表
        Node *cur = head;
        Node *tmp;
        while (cur != nullptr) {
            tmp = new Node(cur -> val);
            tmp -> next = cur -> next;
            cur -> next = tmp;
            cur = tmp -> next;
        }

        // 拷贝random
        cur = head;
        while (cur != nullptr) {
            if (cur -> random != nullptr) {
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }

        // 拆分
        cur = head;
        Node *new_head = cur -> next;
        tmp = nullptr;
        while (cur != nullptr) {
            Node *nxt = cur -> next;
            cur -> next = nxt -> next;
            nxt -> next = nullptr;
            if (tmp != nullptr) {
                tmp -> next = nxt;
            } 
            tmp = nxt;
            cur = cur -> next;
        }
        
        return new_head;

    }
};