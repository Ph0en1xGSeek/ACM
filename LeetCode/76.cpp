class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int num = 0;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]]++;
            num++;
        }
        int left = 0;
        int result = 100000000;
        string ret = "";
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] > 0){
                num--;
            }
            mp[s[i]]--;
            while(num == 0){
                if(result > i - left + 1){
                    result  = i - left + 1;
                    ret = s.substr(left, result);
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    num++;
                }
                left++;
            }
        }
        return ret;
    }
};