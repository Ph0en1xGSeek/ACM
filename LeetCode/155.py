class MinStack(object):

    stack = []
    minpos = []
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minpos = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        if len(self.stack) == 1:
            self.minpos.append(0)
        elif x < self.stack[self.minpos[-1]]:
            self.minpos.append(len(self.stack) - 1)
        

    def pop(self):
        """
        :rtype: void
        """
        if len(self.stack) == 0:
            return
        if self.minpos[-1] == len(self.stack) - 1:
            del self.minpos[-1]
        del self.stack[-1]
        

    def top(self):
        """
        :rtype: int
        """
        if len(self.stack) == 0:
            return None
        else:
            return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.stack) == 0:
            return None
        else:
            return self.stack[self.minpos[-1]]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()