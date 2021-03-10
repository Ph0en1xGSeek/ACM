/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func getMinimumDifference(root *TreeNode) int {
	var ans int = int(^uint(0) >> 1)
	var pre *TreeNode = nil
	cur := root
	for cur != nil {
		if cur.Left != nil {
			tmp := cur.Left;
			for tmp.Right != nil && tmp.Right != cur {
				tmp = tmp.Right
			}
			if tmp.Right == cur {
				tmp.Right = nil
                if pre != nil {
                    var diff int
                    if(pre.Val < cur.Val) {
                        diff = cur.Val - pre.Val
                    }else {
                        diff = pre.Val - cur.Val
                    }
                    if diff < ans {
                        ans = diff
                    }
                }
                pre = cur
				cur = cur.Right;
			}else {
				tmp.Right = cur
				cur = cur.Left;
			}
		} else {
            if pre != nil {
                var diff int
                if(pre.Val < cur.Val) {
                    diff = cur.Val - pre.Val
                }else {
                    diff = pre.Val - cur.Val
                }
                if diff < ans {
                    ans = diff
                }
            }
            pre = cur
			cur = cur.Right
		}
	}
	return ans
}
