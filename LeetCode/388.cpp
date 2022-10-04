class Solution {
public:
    int lengthLongestPath(string input) {
        int sum = 0;
        int cnt = 0;
        int ans = 0;
        stack<int> st;
        int sz = input.size();
        int layer = 0;
        int cur_l = 0;
        bool hasDot = false;
        for(int i = 0; i < sz; ++i) {
            if(input[i] != '\n' && input[i] != '\t') {
                ++cnt;
                if(input[i] == '.') {
                    hasDot = true;
                }
            }else if(input[i] == '\n') {
                if(hasDot) {
                    ans = max(ans, sum + cnt + cur_l);
                }
                ++i;

                layer = 0;
                while(i < sz && input[i] == '\t') {
                    ++layer;
                    ++i;
                }
                if(layer > cur_l) {
                    sum += cnt;
                    st.push(cnt);
                }else if(cur_l > layer) {
                    for(int l = 0; l < (cur_l - layer); ++l) {
                        int tmp = st.top();
                        st.pop();
                        sum -= tmp;
                    }
                    
                }
                cur_l = layer;
                cnt = 0;
                --i;
                hasDot = false;
            }
        }
        if(hasDot) {
            ans = max(ans, sum + cnt + cur_l); 
        }
        return ans;
    }
};