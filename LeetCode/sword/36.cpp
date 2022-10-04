/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *head = nullptr;
        Node *pre = nullptr;
        dfs(root, pre, head);
        pre -> right = head;
        head ->left = pre;
        return head;
    }

    void dfs(Node *cur, Node* &pre, Node* &head) {
        if (cur == nullptr) {
            return;
        }
        dfs(cur -> left, pre, head);
        if (head == nullptr) {
            head = cur;
        }
        if (pre != nullptr) {
            pre -> right = cur;
            cur -> left = pre;
        }
        pre = cur;
        dfs(cur -> right, pre, head);
    }
};