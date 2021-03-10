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
  * @param head ListNode类 
  * @param n int整型 
  * @return ListNode类
*/
func removeNthFromEnd( head *ListNode ,  n int ) *ListNode {
    // write code here
    tail := head;
    for i := 0; i < n; i++ {
        if tail == nil {
            return nil
        }
        tail = tail.Next
    }
    cur := head
    var pre *ListNode = nil
    for tail != nil {
        pre = cur
        cur = cur.Next
        tail = tail.Next
    }
    if pre == nil {
        head = head.Next
        cur.Next = nil
    }else {
        pre.Next = cur.Next
        cur.Next = nil
    }
    return head
}