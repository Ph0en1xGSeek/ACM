class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        //s[i]之前（不算i）与p[j]之前的字符串是否能够匹配
        bool **dp = new bool *[lens+1];
        for(int i = 0; i <= lens; i++)
            dp[i] = new bool [lenp+1];
        bool res = false;
        dp[0][0] = true;
        for(int i = 1; i <= lens; i++)
        {
            dp[i][0] = false;
        }
        for(int j = 1; j <= lenp; j++)
        {
            if(j > 1 && p[j-1] == '*' && dp[0][j-2])
                dp[0][j] = true;
            else
                dp[0][j] = false;
        }
        
        for(int i = 1; i <= lens; i++)
        {
            for(int j = 1; j <= lenp; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        res = dp[lens][lenp];
        for(int i = 0; i <= lens; i++)
            delete [] dp[i];
        delete [] dp;
        return res;
    }
};


class Solution {
private:
    int size_s;
    int size_p;
public:


    bool isMatchByPos(const string &s, int pos_s, const string &p, int pos_p) {
        if (pos_s == size_s && pos_p == size_p) {
            return true;
        } else if (pos_p == size_p) {
            return false;
        } else if (pos_p < size_p - 1 && p[pos_p + 1] == '*') {
            if (pos_s < size_s && (s[pos_s] == p[pos_p] || p[pos_p] == '.')) {
                return isMatchByPos(s, pos_s + 1, p, pos_p) || isMatchByPos(s, pos_s, p, pos_p + 2);
            } else {
                return isMatchByPos(s, pos_s, p, pos_p + 2);
            }
        } else {
            if (pos_s < size_s && (s[pos_s] == p[pos_p] || p[pos_p] == '.')) {
                return isMatchByPos(s, pos_s + 1, p, pos_p + 1);
            } else {
                return false;
            }
        }
    }

    bool isMatch(const string &s, const string &p) {
        size_s = s.size();
        size_p = p.size();
        return isMatchByPos(s, 0, p, 0);
    }
};