/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) {
            return pNode;
        }
        if(pNode->right != nullptr) {
            TreeLinkNode *nex = pNode->right;
            while(nex->left != nullptr) {
                nex = nex->left;
            }
            return nex;
        }else {
            TreeLinkNode *nex = pNode->next, *pre = pNode;
            while(nex != nullptr && nex->right == pNode) {
                pNode = nex;
                nex = nex->next;
            }
            return nex;
        }
    }
};