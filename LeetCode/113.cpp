/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* buildTree(ListNode** head, int from, int to){
        if(from == to){
            return NULL;
        }
        TreeNode * cur = new TreeNode(0);
        int mid = ((to+from)>>1);
        cur->left = buildTree(head, from, mid);
        cur->val = (*head)->val;
        (*head) = (*head)->next;
        cur->right = buildTree(head, mid+1, to);
        return cur;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        int cnt = 0;
        ListNode *cur = head;
        while(cur != NULL){
            cur = cur->next;
            cnt++;
        }
        return buildTree(&head, 0, cnt);
    }
};