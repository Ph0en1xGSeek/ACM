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