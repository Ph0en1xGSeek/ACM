/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *cur = root;
        if(root == NULL){
            return root;
        }
        while(cur->left != NULL){
            Node *tmp = cur;
            while(tmp != NULL){
                tmp->left->next = tmp->right;
                if(tmp->next != NULL){
                    tmp->right->next = tmp->next->left;
                }
                tmp = tmp->next;
            }
            cur = cur->left;
        }
        return root;
    }
};