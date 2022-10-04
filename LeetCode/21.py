# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        i = l1
        prei = i
        j = l2
        prej = j
        head = tmp = ListNode(0)
        while i != None and j != None:
            tmp.next = ListNode(0)
            tmp = tmp.next
            if i.val < j.val:
                tmp.val = i.val
                prei = i
                i = i.next
            else:
                tmp.val = j.val
                prej = j
                j = j.next
        if i != None:
            tmp.next = i
        if j != None:
            tmp.next = j
        return head.next