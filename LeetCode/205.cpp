class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if(s_len != t_len){
            return false;
        }
        unordered_map<char, char> mp;
        unordered_map<char, char> r_mp;
        for(int i = 0; i < s_len; i++){
            if(mp.count(s[i]) != 0 && mp[s[i]] != t[i])
                return false;
            if(r_mp.count(t[i]) != 0 && r_mp[t[i]] != s[i])
                return false;
            mp[s[i]] = t[i];
            r_mp[t[i]] = s[i];
        }
        return true;
    }
};