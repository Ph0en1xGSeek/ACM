# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        i = j = head
        while True:
            i = i.next
            if i == None:
                return False
            j = j.next
            if j == None:
                return False
            j = j.next
            if j == None:
                return False
            if i == j:
                return True
        