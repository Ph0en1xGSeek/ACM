# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def check(self, root):
        if root == None:
            return (True, 0)
        lnum = self.check(root.left)
        rnum = self.check(root.right)
        if lnum[0] == False or rnum[0] == False:
            return (False, 0)
        if abs(lnum[1] - rnum[1]) > 1:
            return (False, 0)
        else:
            return (True, max(lnum[1], rnum[1])+1)
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.check(root)[0]
        
        