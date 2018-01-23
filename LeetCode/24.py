# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        ret = head.next
        i = head
        j = head.next
        pre = None
        while j != None:
            i.next = j.next
            j.next = i
            if pre != None:
                pre.next = j
            if i.next != None:
                pre = i
                i = i.next
                j = i.next
            else:
                break
        return ret