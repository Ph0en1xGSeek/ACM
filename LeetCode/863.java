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
    TreeNode target;
    int K;
    List<Integer> ans;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        this.K = K;
        this.target = target;
        ans = new LinkedList<Integer>();
        if(K == 0) {
            ans.add(target.val);
            return ans;
        }
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode cur) {
        if(cur == null) {
            return -1;
        }
        if(cur == target) {
            add_subtree(cur, 0);
            return 1;
        }
        int left = dfs(cur.left);
        int right = dfs(cur.right);
        if(left == -1 && right == -1) {
            return -1;
        }else if(left != -1) {
            if(left == K) {
                ans.add(cur.val);
            }else if(left < K) {
                add_subtree(cur.right, left + 1);
            }
            return left + 1;
        }else {
            if(right == K) {
                ans.add(cur.val);
            }else if(right < K) {
                add_subtree(cur.left, right + 1);
            }
            return right + 1;
        }
    }

    private void add_subtree(TreeNode cur, int deep) {
        if(cur == null) {
            return;
        }
        if(deep == K) {
            ans.add(cur.val);
        }else {
            add_subtree(cur.left, deep+1);
            add_subtree(cur.right, deep+1);
        }
    }
}