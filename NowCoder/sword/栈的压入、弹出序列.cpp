class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pos = 0;
        int sz_push = pushV.size();
        int sz_pop = popV.size();
        if(sz_push != sz_pop) {
            return false;
        }
        
        for(int i = 0; i < sz_pop; ++i) {
            if(st.empty() || popV[i] != st.top()) {
                while(pos < sz_push && pushV[pos] != popV[i]) {
                    st.push(pushV[pos]);
                    ++pos;
                }
                if(pos < sz_push) {
                    ++pos;
                }else {
                    return false;
                }
            }else {
                st.pop();
            }
        }
        return true;
    }
private:
    stack<int> st;
};