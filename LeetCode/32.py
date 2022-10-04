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


// CPP
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int sz = s.size();
        int ans = 0;
        int cnt = 0;
        stack<int> st;
        for(int i = 0; i < sz; ++i) {
            if(s[i] == '(') {
                st.push(i);
            }else {
                if(!st.empty()) {
                    st.pop();
                    if(st.empty()) {
                        cnt = i - left + 1;
                    }else {
                        int pre = st.top();
                        cnt = i - pre;
                    }
                    
                    ans = max(ans, cnt);
                }else {
                    left = i+1;
                }
            }
        }
        return ans;
        
    }
};