// Recursion
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        int sz = str.size();
        if(sz == 0) {
            return ret;
        }
        recursion(ret, str, 0);
        sort(ret.begin(), ret.end());
        return ret;
    }
    
    void recursion(vector<string> &ret, string &str, int pos) {
        if(pos == str.size()-1) {
            ret.push_back(str);
            return;
        }
        bool swapped = false;
        for(int i = pos; i < str.size(); ++i) {
            if(i == pos || str[i] != str[pos]) {
                swap(str[pos], str[i]);
                swapped = true;
                recursion(ret, str, pos+1);
                swap(str[pos], str[i]);
            }
        }
        if(swapped == false) {
            ret.push_back(str);
        }
    }
};



// Iteration
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        int sz = str.size();
        if(sz == 0) {
            return ret;
        }
        sort(str.begin(), str.end(), [](const char &a, const char &b) {
            char lower_a = a > 'Z'? a - 'a' + 'A': a;
            char lower_b = b > 'Z'? b - 'a' + 'A': b;
            if(lower_a == lower_b) {
                return a < b;
            }
            return lower_a < lower_b;
        });
        ret.push_back(str);
        while(true) {
            int q = sz-2, p;
            while(q >= 0 && str[q] >= str[q+1]) --q;
            if(q < 0) break;
            p = q + 1;
            while(p < sz && str[p] > str[q]) ++p;
            --p;
            swap(str[p], str[q]);
            reverse(str.begin() + q + 1, str.end());
            ret.push_back(str);
        }
        return ret;
    }
};