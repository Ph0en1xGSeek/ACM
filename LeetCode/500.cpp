class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<char> row(128, 0);
        string str1 = "qwertyuiopQWERTYUIOP";
        string str2 = "asdfghjklASDFGHJKL";
        string str3 = "zxcvbnmZXCVBNM";
        for(char c: str1) {
            row[c] = 1;
        }
        for(char c: str2) {
            row[c] = 2;
        }
        for(char c: str3) {
            row[c] = 3;
        }
        int size = words.size();
        vector<string> ans;
        for(int i = 0; i < size; ++i) {
            int str_size = words[i].size();
            int at = row[words[i][0]];
            bool flag = true;
            for(int j = 1; j < str_size; ++j) {
                if(row[words[i][j]] != at) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};