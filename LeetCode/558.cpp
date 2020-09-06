/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node *ret = nullptr;
        if(quadTree1 == nullptr || quadTree2 == nullptr) {
            return ret;
        }
        if((quadTree1->isLeaf == true && quadTree1->val == true) || (quadTree2->isLeaf == true && quadTree2->val == true)) {
            return new Node(true, true);
        }
        if(quadTree1->isLeaf == true && quadTree1->val == false) {
            return new Node(quadTree2->val,
                            quadTree2->isLeaf,
                            quadTree2->topLeft,
                            quadTree2->topRight,
                            quadTree2->bottomLeft,
                            quadTree2->bottomRight);
        }
        if(quadTree2->isLeaf == true && quadTree2->val == false) {
            return new Node(quadTree1->val,
                            quadTree1->isLeaf,
                            quadTree1->topLeft,
                            quadTree1->topRight,
                            quadTree1->bottomLeft,
                            quadTree1->bottomRight);
        }
        ret = new Node();
        ret->isLeaf = false;
        ret->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        ret->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        ret->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        ret->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if(ret->topLeft->isLeaf == true
         && ret->topRight->isLeaf == true && ret->topLeft->val == ret->topRight->val
         && ret->bottomLeft->isLeaf == true && ret->topLeft->val == ret->bottomLeft->val 
         && ret->bottomRight->isLeaf == true && ret->topLeft->val == ret->bottomRight->val) {
            ret->isLeaf = true;
            ret->val = ret->topLeft;
            delete ret->topLeft;
            delete ret->topRight;
            delete ret->bottomLeft;
            delete ret->bottomRight;
            ret->topLeft = ret->topRight = ret->bottomLeft = ret->bottomRight = nullptr;
        }
        return ret;
    }
};




