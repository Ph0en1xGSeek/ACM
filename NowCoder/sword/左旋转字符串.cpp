class Solution {
public:
    void reverse_str(string &str, size_t from, size_t to) {
        if(from >= to) {
            return;
        }
        while(from < to) {
            swap(str[from], str[to]);
            --to;
            ++from;
        }
    }
    
    string LeftRotateString(string str, int n) {
        size_t sz = str.size();
        if(sz == 0) {
            return str;
        }
        n %= sz;
        if(n == 0) {
            return str;
        }
        reverse_str(str, 0, n-1);
        reverse_str(str, n, sz-1);
        reverse_str(str, 0, sz-1);
        return str;
    }
};