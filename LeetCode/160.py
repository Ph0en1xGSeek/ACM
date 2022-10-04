# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA == None or headB == None:
            return None
        cnt1 = cnt2 = 0
        i = headA
        j = headB
        while i != None:
            i = i.next
            cnt1 += 1
        while j != None:
            j = j.next
            cnt2 += 1
        i = headA
        j = headB
        if cnt1 > cnt2:
            for _ in range(cnt1 - cnt2):
                i = i.next
        else:
            for _ in range(cnt2 - cnt1):
                j = j.next
        while i != j:
                i = i.next
                j = j.next
        return i