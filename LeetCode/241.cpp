class Solution {
public:
    unordered_map<string, vector<int> > mp;
    
    vector<int> diffWaysToCompute(string input) {
        if(mp.find(input) != mp.end()) {
            return mp[input];
        }
        vector<int> res;
        for(int i = 0; i < input.size(); ++i) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> il = diffWaysToCompute(input.substr(0, i));
                vector<int> ir = diffWaysToCompute(input.substr(i+1));
                for(int l: il) {
                    for(int r: ir) {
                        if(input[i] == '+')
                            res.push_back(l + r);
                        else if(input[i] == '-')
                            res.push_back(l - r);
                        else
                            res.push_back(l * r);
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};