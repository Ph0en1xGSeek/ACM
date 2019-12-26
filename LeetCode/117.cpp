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
        if(root == NULL){
            return root;
        }
        Node * cur = root;
        while(cur != NULL){
            Node *nex = NULL; //node that found first next layer
            Node *pre = NULL; // last found node next layer
            Node *tmp = cur;
            while(tmp != NULL){
                if(tmp->left != NULL){
                    if(pre != NULL){
                        pre->next = tmp->left;
                    }
                    pre = tmp->left;
                    if(nex == NULL){
                        nex = tmp->left;
                    }
                }
                if(tmp->right != NULL){
                    if(pre != NULL){
                        pre->next = tmp->right;
                    }
                    pre = tmp->right;
                    if(nex == NULL){
                        nex = tmp->right;
                    }
                }
                tmp = tmp->next;
            }
            cur = nex;
        }
        return root;
    }
};