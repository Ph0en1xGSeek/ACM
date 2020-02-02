/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) {
            return head;
        }
        Node *cur = head;
        while(cur != nullptr) {
            if(cur->child != nullptr) {
                Node *tmp = cur->child;
                while(tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                tmp->next = cur->next;
                if(cur->next != nullptr)
                    cur->next->prev = tmp;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            cur = cur->next;
        }
        return head;
    }
};