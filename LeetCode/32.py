class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        mx = 0
        arr = [False]*len(s)
        st = []
        for i in range(len(s)):
            if s[i] == '(':
                left += 1
                st.append(i)
            else:
                if left > 0:
                    left -= 1
                    arr[st[-1]] = True
                    arr[i] = True
                    st.pop(-1)
                else:
                    st = []

        cnt = 0
        for i in range(len(s)):
            if arr[i]:
                cnt += 1
            else:
                mx = max(mx, cnt)
                cnt = 0
        mx = max(mx, cnt)
        return mx