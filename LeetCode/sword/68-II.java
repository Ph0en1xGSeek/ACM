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
    private TreeNode ans, p, q;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode cur) {
        if(cur == null) {
            return 0;
        }
        int left = dfs(cur.left);
        int right = dfs(cur.right);
        int root = 0;
        if(cur == p || cur == q) {
            root = 1;
        }
        root += left + right;
        if(root == 2 && ans == null) {
            ans = cur;
        }
        return root;
    }
}