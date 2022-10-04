class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran_cnt[26] = {0};
        for(int i = 0; i < magazine.size(); ++i) {
            ++ran_cnt[magazine[i] - 'a'];
        }
        
        for(int i = 0; i < ransomNote.size(); ++i) {
            --ran_cnt[ransomNote[i] - 'a'];
            if(ran_cnt[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};