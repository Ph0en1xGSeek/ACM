# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        res = root = ListNode(-1)
        root.next = head
        tmp = head
        cnt = 0
        while(tmp != None):
            tmp = tmp.next
            cnt += 1
        while(cnt >= k):
            for i in range(k-1):
                node = root.next
                root.next = head.next
                head.next = root.next.next
                root.next.next = node
            root = head
            head = head.next
            cnt -= k
        return res.next