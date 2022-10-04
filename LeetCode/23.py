# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        heap = []
        i = 0
        for node in lists:
            if node != None:
                heap.append((node.val, i, node))
                i += 1
        heapq.heapify(heap)
        cur = head = ListNode(0)
        while heap:
            pop = heapq.heappop(heap)
            cur.next = ListNode(pop[0])
            cur = cur.next
            if pop[2].next != None:
                heapq.heappush(heap, (pop[2].next.val, i, pop[2].next))
                i += 1
        return head.next
                
