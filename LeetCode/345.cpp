class Solution {
public:
    string reverseVowels(string s) {
        
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        
        int sz = s.size();
        int i = 0;
        int j = sz-1;
        while(i < j) {
            while(i < j && st.find(s[i]) == st.end()) {
                ++i;
            }
            while(i < j && st.find(s[j]) == st.end()) {
                --j;
            }
            if(i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};