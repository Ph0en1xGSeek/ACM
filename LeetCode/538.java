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
    public TreeNode convertBST(TreeNode root) {
	TreeNode cur = root;
	TreeNode pre = null;
	while(cur != null) {
		if(cur.right != null) {
			TreeNode tmp = cur.right;
			while(tmp.left != null && tmp.left != cur) {
				tmp = tmp.left;
			}
			if(tmp.left == cur) {
				tmp.left = null;
				if(pre != null) {
					cur.val += pre.val;
				}
				pre = cur;
				cur = cur.left;
			}else {
				tmp.left = cur;
				cur = cur.right;
			}
		} else {
			if(pre != null) {
				cur.val += pre.val;
			}
            pre = cur;
			cur = cur.left;
		}
	}
	return root;
    }
}
