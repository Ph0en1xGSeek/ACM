class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len == 0){
            return "";
        }
        string long_s(2 * len + 2, '$');
        long_s[0] =  '^';
        for(int i = 0; i < len; i++){
            long_s[(i << 1) + 1] = '#';
            long_s[(i << 1) + 2] = s[i];
        }
        long_s[(len << 1) + 1] = '#';
        int center = 0, r = 0;
        vector<int> p(2 * len + 2, 0);
        for(int i = 1; i < long_s.length() - 1; i++){
            if(i < r){
                p[i] = min(r - i, p[2 * center - i]);
            }else{
                p[i] = 1;
            }
            
            while(long_s[i - p[i]] == long_s[i + p[i]]){
                p[i]++;
            }
            if(i + p[i] > r){
                r = i + p[i];
                center = i;
            }
        }
        int mx = 1;
        for(int i = 1; i < long_s.length() - 1; i++){
            if(i - p[i] == 0){
                mx = p[i];
            }
        }
        string new_str = s.substr(mx - 1);
        reverse(new_str.begin(), new_str.end());
        new_str += s;
        return new_str;
    }
};