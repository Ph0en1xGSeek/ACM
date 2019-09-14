class Solution {
public:
    string add(const string &a, const string &b) {
        int size_a = a.size();
        int size_b = b.size();
        if((size_a > 1 && a[0] == '0') || (size_b > 1 && b[0] == '0')) {
            return "$";
        }
        int len = max(size_a, size_b);
        vector<int> num_a(len, 0), num_b(len, 0), num_c(len+1, 0);
        for(int i = 0; i < size_a; ++i) {
            num_a[size_a - i - 1] = a[i] - '0';
        }
        for(int i = 0; i < size_b; ++i) {
            num_b[size_b - i - 1] = b[i] - '0';
        }
        for(int i = 0 ; i < len; ++i) {
            num_c[i] += num_a[i] + num_b[i];
            num_c[i+1] += num_c[i] / 10;
            num_c[i] %= 10;
        }
        string c = "";
        if(num_c[len] != 0) {
            c += num_c[len] + '0';
        }
        for(int i = len-1; i >= 0; --i) {
            c += num_c[i] + '0';
        }
        return c;
    }
    
    bool check(string &num, int first, int second) {
        int last = -1;
        
        do{
            string res = add(num.substr(last+1, first - last), num.substr(first+1, second - first));
            int size_res = res.size();
            for(int i = second + 1, j = 0; j < size_res; ++i, ++j) {
                if(i == num.size() || res[j] != num[i]) {
                    return false;
                }
            }
            last = first;
            first = second;
            second = second + size_res;
        }while(second < num.size() - 1);

        return true;
    }
    
    bool isAdditiveNumber(string num) {
        int sz = num.size();
        for(int first = 0; first < sz - 1; ++first) {
            for(int second = first + 1; second < sz - 1; ++second) {
                if(check(num, first, second))
                    return true;
            }
        }
        return false;
    }
};