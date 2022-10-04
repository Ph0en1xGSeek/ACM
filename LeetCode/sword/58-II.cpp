class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        string res = s.substr(n) + s.substr(0, n);
        return res;
    }
};