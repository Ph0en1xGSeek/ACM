class Solution {
public:
    
    void dfs(string s, string cur_str, int k, vector<string>& result){
        if(s.length() == 0 && k == 4){
            result.push_back(cur_str.substr(0, cur_str.length()-1));
        }
        if(s.length() == 0 || k == 4){
            return;
        }
        for(int i = 1; i <= min(3, (int)s.length()); i++){
            string nex_str = s.substr(0, i);
            int val = stoi(nex_str);
            if(val >= 0 && val <= 255){
                dfs(s.substr(i), cur_str + nex_str + ".", k+1, result);
            }
            if(s[0] == '0')
                break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.length() == 0){
            return result;
        }
        dfs(s, "", 0, result);
        return result;
    }
};