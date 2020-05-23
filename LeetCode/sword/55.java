/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root == null) {
            return true;
        }
        int d = depth(root);
        if(d != -1) {
            return true;
        }else {
            return false;
        }
        
    }

    public int depth(TreeNode node) {
        if(node == null) {
            return 0;
        }
        int leftDepth = depth(node.left);
        int rightDepth = depth(node.right);
        if(leftDepth == -1 || rightDepth == -1) {
            return -1;
        }
        if(leftDepth - rightDepth > 1 || leftDepth - rightDepth < -1) {
            return -1;
        }
        return Math.max(leftDepth + 1, rightDepth + 1);
    }
}