# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        lnum = self.minDepth(root.left)
        rnum = self.minDepth(root.right)
        if lnum == 0 and rnum == 0:
            return 1
        elif lnum == 0:
            return rnum+1
        elif rnum == 0:
            return lnum+1
        else:
            return min(rnum, lnum) + 1