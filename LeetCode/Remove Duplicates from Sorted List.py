# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        i = j = head
        while i != None:
            while j != None and j.val == i.val:
                j = j.next
            i.next = j
            i = i.next
        return head
        