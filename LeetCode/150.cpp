class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            }else if(tokens[i] == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }else if(tokens[i] == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }else if(tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }else{
                int sign = 1;
                int num = 0;
                int j = 0;
                if(tokens[i][j] == '-'){
                    sign = -1;
                    j++;
                }
                for(; j < tokens[i].length(); j++){
                    num *= 10;
                    num +=  tokens[i][j] - '0';
                }
                st.push(sign*num);
            }
        }
        int ans = st.top();
        return ans;
    }
};