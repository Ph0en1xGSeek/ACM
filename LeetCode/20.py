class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        arr = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                arr.append(i)
            elif i == ')':
                if len(arr) > 0 and arr[-1] == '(':
                    arr.pop()
                else:
                    return False
            elif i == ']':
                if len(arr) > 0 and arr[-1] == '[':
                    arr.pop()
                else:
                    return False
            elif i == '}':
                if len(arr) > 0 and arr[-1] == '{':
                    arr.pop()
                else:
                    return False
        if len(arr) > 0:
            return False
        
        return True