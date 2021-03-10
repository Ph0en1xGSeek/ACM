class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) {
            return -1;
        }else {
            int a_size = a.size();
            int b_size = b.size();
            return max(a_size, b_size);
        }
    }
};