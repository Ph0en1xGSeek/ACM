# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSame(self, p, q):
        if p == None and q == None:
            return True
        elif p == None or q == None:
            return False
        if p.val == q.val:
            return self.isSame(p.left, q.right) and self.isSame(p.right, q.left)
        else:
            return False
        
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.isSame(root.left, root.right)
    