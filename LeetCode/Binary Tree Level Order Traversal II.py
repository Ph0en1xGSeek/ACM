# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        result = []
        q = [root]
        while(len(q) > 0):
            tmp = []
            for i in range(len(q)):
                if q[0] != None:
                    tmp.append(q[0].val)
                if q[0].left != None:
                    q.append(q[0].left)
                if q[0].right != None:
                    q.append(q[0].right)
                q.pop(0)
            result.insert(0, tmp)
        return result
            
        