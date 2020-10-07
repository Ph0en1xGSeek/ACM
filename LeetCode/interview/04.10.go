/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func checkSubTree(t1 *TreeNode, t2 *TreeNode) bool {
    if t2 == nil || t1 == nil {
        return false
    }
    if t1.Val == t2.Val && compare(t1, t2) {
        return true
    }else {
        return checkSubTree(t1.Left, t2) || checkSubTree(t1.Right, t2)
    }
}

func compare(t1 *TreeNode, t2 *TreeNode) bool {
    if (t1 == nil && t2 != nil) || (t1 != nil && t2 == nil) {
        return false;
    }
    if t1 == nil && t2 == nil {
        return true
    }
    if t1.Val == t2.Val {
        return compare(t1.Left, t2.Left) && compare(t1.Right, t2.Right)
    }else {
        return false
    }
}