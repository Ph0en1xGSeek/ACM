class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        n = len(strs)
        if n > 0:
            cur = strs[0]
        else:
            cur = ''
        for str in strs:
            if not str.startswith(cur):
                ra = min(len(cur), len(str))
                i = 0
                while(i < ra and str[i] == cur[i]):
                    i += 1
                    
                if i == 0:
                    return ''
                cur = cur[0:i]
        return cur