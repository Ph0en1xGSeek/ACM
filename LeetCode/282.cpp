class Solution {
public:
    void dfs(vector<string> &ret, long long curNum, long long mulNum, long long pos, string res, string &num, int target) {
        if(pos == num.size()) {
            if(curNum == target) {
                ret.push_back(res);
            }
        }
        long long mx_num = num[pos] - '0';
        for(int i = pos+1; i < num.size(); ++i) {
            mx_num *= 10;
            mx_num += num[i] - '0';
        }
        long long cur_num = 0;
        for(int i = pos; i < num.size(); ++i) {
            if(num[pos] == '0' && i != pos)
                break;
            cur_num *= 10;
            cur_num += num[i] - '0';
            if(pos == 0) {
                dfs(ret, cur_num, cur_num, i+1, num.substr(0, i+1), num, target);
            } else {
                dfs(ret, curNum - mulNum + mulNum * cur_num, mulNum * cur_num, i+1, res + "*" + num.substr(pos, i-pos+1), num, target);
                if(curNum + mx_num >= target) {
                    dfs(ret, curNum + cur_num, cur_num, i+1, res + "+" + num.substr(pos, i-pos+1), num, target);
                }
                if(curNum - mx_num <= target) {
                    dfs(ret, curNum - cur_num, -cur_num, i+1, res + "-" + num.substr(pos, i-pos+1), num, target);
                }
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        dfs(ret, 0, 0, 0, "", num, target);
        return ret;
    }
};