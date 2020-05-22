class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        int size = s.size();
        if(size == 0) {
            return ans;
        }
        sort(s.begin(), s.end());
        while(true) {
            ans.push_back(s);
            int pos = size - 1;
            while(pos > 0 && s[pos] <= s[pos-1]) {
                --pos;
            }
            if(pos == 0) {
                break;
            }
            int tmp = pos;
            --pos;
            while(tmp < size && s[tmp] > s[pos]) {
                ++tmp;
            }
            --tmp;
            swap(s[pos], s[tmp]);
            reverse(s.begin() + pos + 1, s.end());
        }
        return ans;
    }
};