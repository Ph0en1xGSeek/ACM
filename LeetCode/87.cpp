class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        int size1 = s1.length();
        int size2 = s2.length();
        if(size1 != size2)
            return false;
        vector<int> cnt;
        cnt.resize(26);
        for(int i = 0; i < size1; i++){
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0)
                return false;
        }
        for(int i = 1; i < size1; i++){
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, size1-i), s2.substr(i, size1-i))) ||
              (isScramble(s1.substr(0, i), s2.substr(size1-i)) && isScramble(s1.substr(i, size1-i), s2.substr(0, size1-i))))
                return true;
        }
        return false;
    }
};