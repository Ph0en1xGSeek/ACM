package main
import . "nc_tools"
/*
 * type ListNode struct{
 *   Val int
 *   Next *ListNode
 * }
 */

/**
  * 
  * @param l1 ListNode类 
  * @param l2 ListNode类 
  * @return ListNode类
*/
func mergeTwoLists( l1 *ListNode ,  l2 *ListNode ) *ListNode {
    // write code here
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    
    if l1.Val > l2.Val {
        tmp := l1
        l1 = l2
        l2 = tmp
    }
    var pre *ListNode = nil
    cur := l1
    for cur != nil && l2 != nil {
        if cur.Val <= l2.Val {
            pre = cur
            cur = cur.Next
        }else {
            pre.Next = l2
            l2 = l2.Next
            pre.Next.Next = cur
            pre = pre.Next
        }
    }
    if l2 != nil {
        pre.Next = l2
    }
    return l1
}