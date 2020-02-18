class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(string tok: tokens) {
            if(tok == "+") {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                st.push(rhs + lhs);
            }else if(tok == "-") {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                st.push(lhs - rhs);
            }else if(tok == "/") {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                st.push(lhs / rhs);
            }else if(tok == "*") {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                st.push(lhs * rhs);
            }else {
                int sign = 1;
                int num = 0;
                int sz = tok.size();
                int i = 0;
                if(tok[i] == '-') {
                    sign = -1;
                    i = 1;
                }
                for(; i < sz; ++i) {
                    num *= 10;
                    num += tok[i] - '0';
                }
                st.push(sign * num);
             }
        }
        return st.top();
    }
};