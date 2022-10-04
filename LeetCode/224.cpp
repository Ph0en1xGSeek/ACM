class Solution {
public:
    
    stack<int> st;
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = (s[i] - '0') + num * 10;
                    ++i;
                }
                res += sign * num;
                --i;
            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }else if(s[i] == ')'){
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }else if(s[i] == '+'){
                sign = 1;
            }else if(s[i] == '-'){
                sign = -1;
            }
        }
        return res;
    }
};