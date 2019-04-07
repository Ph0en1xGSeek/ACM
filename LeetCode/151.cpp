class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int len = s.length();
        int cur_pos = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != ' '){
                if(cur_pos != 0)
                    s[cur_pos++] = ' ';
                int j = i;
                while(j < len && s[j] != ' '){
                    s[cur_pos++] = s[j++];
                }
                reverse(s.begin() + cur_pos - (j-i), s.begin() + cur_pos);
                i = j;
            }
        }
        s.resize(cur_pos);
        return s;
    }
};