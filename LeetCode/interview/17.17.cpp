class Solution {
public:

    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        memset(sons, 0, sizeof(sons));
        memset(keys, 0, sizeof(keys));
        big_size = big.size();
        small_size = smalls.size();
        for(int i = 0; i < small_size; ++i) {
            if(smalls[i].size() > 0)
                insert(smalls[i]);
        }
        unordered_map<string, vector<int>> hash;
        for(int i = 0; i < big_size; ++i) {
            search(big, i, hash);
        }
        vector<vector<int>> ret(small_size);
        for(int i = 0; i < small_size; ++i) {
            if(smalls[i].size() > 0 && hash.find(smalls[i]) != hash.end()) {
                ret[i] = hash[smalls[i]];
            }
        }
        return ret;
    }
private:
    int big_size;
    int small_size;
    int pos = 0;
    string keys[100001];
    int sons[100001][26];
    void insert(string &str) {
        int cur = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(sons[cur][str[i] - 'a'] == 0) {
                sons[cur][str[i] - 'a'] = ++pos;
            }
            cur = sons[cur][str[i] - 'a'];
        }
        keys[cur] = str;
    }

    void search(string &str, int from, unordered_map<string, vector<int>> &mp) {
        int cur = 0;
        for(int i = from; i < str.size(); ++i) {
            if(sons[cur][str[i] - 'a'] == 0) {
                return;
            }
            cur = sons[cur][str[i] - 'a'];
            if(keys[cur] != "") {
                mp[keys[cur]].push_back(from);
            }
        }
    }
};