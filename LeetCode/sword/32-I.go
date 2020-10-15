/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func levelOrder(root *TreeNode) []int {
    ans := []int{}
    if root == nil {
        return ans
    }
    q := []*TreeNode{root}
    for len(q) != 0 {
        cur := q[0]
        ans = append(ans, cur.Val)
        q = q[1:]
        if cur.Left != nil {
            q = append(q, cur.Left)
        }
        if cur.Right != nil {
            q = append(q, cur.Right)
        }
    }
    return ans
    
}