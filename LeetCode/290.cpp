class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mp;
        map<string, char> mp2;
        vector<string> vec;
        string tmp;
        istringstream is(str);
        while(is >> tmp) {
            vec.push_back(tmp);
        }
        int sz = pattern.size();
        if(vec.size() != sz) {
            return false;
        }
        for(int i = 0; i < sz; ++i) {
            if(mp.find(pattern[i]) == mp.end() && mp2.find(vec[i]) == mp2.end()) {
                mp[pattern[i]] = vec[i];
                mp2[vec[i]] = pattern[i];
            } else if((mp.find(pattern[i]) == mp.end() && mp2.find(vec[i]) != mp2.end()) || (mp.find(pattern[i]) != mp.end() && mp2.find(vec[i]) == mp2.end())) {
                return false;
            } else if(mp[pattern[i]] != vec[i] || mp2[vec[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};