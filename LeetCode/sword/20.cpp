class Solution {
public:
    int size;

    bool isNum(char c) {
        if(c >= '0' && c <= '9') {
            return true;
        }else {
            return false;
        }
    }

    bool isSigned(string &s, int &pos) {
        if(s[pos] == '+' || s[pos] == '-') {
            ++pos;
            return isUnsigned(s, pos);
        }else {
            return isUnsigned(s, pos);
        }
    }

    bool isUnsigned(string &s, int &pos) {
        if(pos == size || !isNum(s[pos])) {
            return false;
        }
        while(pos < size && isNum(s[pos])) {
            ++pos;
        }
        return true;
    }

    bool isNumber(string s) {
        size = s.size();
        int pos = 0;
        while(pos < size && s[pos] == ' ') {
            ++pos;
        }
        bool flag = isSigned(s, pos);
        if(pos < size && s[pos] == '.') {
            ++pos;
            if(pos == size && flag == true) {
            }else {
                flag = isUnsigned(s, pos) || flag;
            }
        }
        if(flag == false) {
            return false;
        }
        if(pos < size && s[pos] == 'e') {
            ++pos;
            flag = isSigned(s, pos);
        }
        while(pos < size && s[pos] == ' ') {
            ++pos;
        }
        if(flag == false || pos < size) {
            return false;
        }
        return true;
    }
};