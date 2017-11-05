# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        i = l1
        j = l2
        tmp = head = ListNode(0)
        jin = 0
        while i != None and j != None:
            sum = i.val + j.val + jin
            jin = 0
            if sum >= 10:
                sum -= 10
                jin = 1
            tmp.next = ListNode(0)
            tmp = tmp.next
            tmp.val = sum
            i = i.next
            j = j.next
        while i != None:
            sum = i.val + jin
            jin = 0
            if sum >= 10:
                sum -= 10
                jin = 1
            tmp.next = ListNode(0)
            tmp = tmp.next
            tmp.val = sum
            i = i.next
        while j != None:
            sum = j.val + jin
            jin = 0
            if sum >= 10:
                sum -= 10
                jin = 1
            tmp.next = ListNode(0)
            tmp = tmp.next
            tmp.val = sum
            j = j.next
        if jin == 1:
            tmp.next = ListNode(0)
            tmp = tmp.next
            tmp.val = 1
        return head.next
                