/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func levelOrder(root *TreeNode) [][]int {
    ans := [][]int{}
    if root == nil {
        return ans
    }
    q := []*TreeNode{root}
    deep := 0
    for len(q) != 0 {
        size := len(q)
        layer := []int{}
        for i := size - 1; i >= 0; i-- {
            cur := q[i]
            layer = append(layer, cur.Val)
            if deep & 1 == 0 {
                if cur.Left != nil {
                    q = append(q, cur.Left)
                }
                if cur.Right != nil {
                    q = append(q, cur.Right)
                }
            }else {
                if cur.Right != nil {
                    q = append(q, cur.Right)
                }
                if cur.Left != nil {
                    q = append(q, cur.Left)
                }
            }
        }
        deep++
        q = q[size:]
        ans = append(ans, layer)
    }
    return ans
    
}