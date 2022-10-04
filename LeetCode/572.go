/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isSubtree(s *TreeNode, t *TreeNode) bool {
    if s == nil {
        return false
    }
    if s.Val == t.Val {
        if compare(s, t) {
            return true
        }
    }
    return isSubtree(s.Left, t) || isSubtree(s.Right, t)
    
}

func compare(s, t *TreeNode) bool {
    if s == nil && t == nil {
        return true
    }
    if s == nil || t == nil {
        return false
    }
    if s.Val != t.Val {
        return false
    }
    return compare(s.Left, t.Left) && compare(s.Right, t.Right)
}