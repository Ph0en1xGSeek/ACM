class Solution {
public:
    void reverse_str(string &str, size_t from, size_t to) {
        if(from >= to) {
            return;
        }
        while(from < to) {
            swap(str[from], str[to]);
            ++from;
            --to;
        }
    }
    
    string ReverseSentence(string str) {
        size_t sz = str.size();
        if(sz == 0) {
            return str;
        }
        reverse_str(str, 0, sz-1);
        size_t from = 0, to = 0;
        while(to < sz) {
            if(str[to] == ' ' && to > from) {
                reverse_str(str, from, to-1);
                ++to;
                from = to;
            }else {
                ++to;
            }
        }
        reverse_str(str, from, to-1);
        return str;
    }
};