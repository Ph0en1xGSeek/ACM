# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        i = j = head
        for _ in range(n):
            j = j.next
        if j == None:
            return head.next
        j = j.next
        while j != None:
            i = i.next
            j = j.next
        
        tmp = i.next
        i.next = tmp.next
        return head