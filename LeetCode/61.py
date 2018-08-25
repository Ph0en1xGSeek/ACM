# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cnt = 0
        end = head
        while end != None:
            cnt += 1
            end = end.next
        if cnt == 0:
            return head
        k %= cnt
        if k == 0:
            return head
        end = head
        start = head
        pre = head
        for i in range(cnt):
            if i == cnt - k - 1:
                pre = end
                start = end.next
            if i != cnt-1:
                end = end.next
        pre.next = None
        end.next = head
        return start
    