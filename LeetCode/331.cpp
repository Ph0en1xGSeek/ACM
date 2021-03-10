class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = 0;
        int sz = preorder.size();
        stack<pair<string, bool>> st;
        bool finished = false;
        while(pos < sz) {
            if(finished == true)
                return false;
            int nex = pos+1;
            while(nex < sz && preorder[nex] != ',' ) ++nex;
            string cur = preorder.substr(pos, nex - pos);
            pos = nex + 1;
            if(cur != "#") {
                st.push(make_pair(cur, false));
            }else {
                while(!st.empty()) {
                    pair<string, bool> tmp = st.top();
                    st.pop();
                    if(tmp.second == false) {
                        tmp.second = true;
                        st.push(tmp);
                        break;
                    }
                }
                if(st.empty()) {
                    finished = true;
                }
            }
        }
        if(!finished) {
            return false;
        }else {
            return true;
        }
    }
};