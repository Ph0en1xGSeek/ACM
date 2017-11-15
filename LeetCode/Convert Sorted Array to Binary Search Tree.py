# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return []
        root = self.make(nums, 0, len(nums)-1)
        return root
        
    def make(self, nums, l, r):
        root = TreeNode(0)
        if l > r:
            return None
        
        if l == r:
            root.val = nums[l]
            return root
        mid = (l+r)>>1
        root.val = nums[mid]
        root.left = self.make(nums, l, mid-1)
        root.right = self.make(nums, mid+1, r)
        return root
        