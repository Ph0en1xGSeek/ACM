class Solution {
public:
    
    void i2a(int num, char* str) {
        size_t pos = 0;
        while(num) {
            str[pos++] = num % 10 + '0';
            num /= 10;
        }
        reverse(str, str + pos);
        str[pos] = '\0';
    }
    
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str_num;
        char ch_num[100];
        for(int elem: numbers) {
            i2a(elem, ch_num);
            str_num.push_back(string(ch_num));
        }
        sort(str_num.begin(), str_num.end(), [](string &s1, string &s2){
            string tmp1 = s1 + s2;
            string tmp2 = s2 + s1;
            return tmp1 < tmp2;
        });
        string ret;
        for(string str: str_num) {
            ret += str;
        }
        return ret;
    }
};