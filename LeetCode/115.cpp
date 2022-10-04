class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if(s_len == 0 || t_len == 0){
            return 0;
        }
        vector<long long> cnt(s_len, 0);
        for(int i = 0; i < s_len; i++){
            if(s[i] == t[0]){
                cnt[i] = 1;
            }
        }
        for(int i = 1; i < t_len; i++){
            long long sum = 0;
            for(int j = 0; j < s_len; j++){
                long long pre = cnt[j];
                if(s[j] == t[i]){
                    cnt[j] = sum;
                }else{
                    cnt[j] = 0;
                }
                sum += pre;
            }
        }
        long long sum = 0;
        for(int i = 0; i < s_len; i++){
            sum += cnt[i];
        }
        return (int)sum;
    }
};