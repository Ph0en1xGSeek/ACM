class Solution {
public:
    bool isNumeric(char* str)
    {
        if(str == NULL) {
            return false;
        }
        bool flag = false;
        flag = isSignedInt(str);
        if(*str == '.') {
            ++str;
            flag = isUnsignedInt(str) || flag;
        }
        if(flag == false) {
            return false;
        }
        if(*str == 'E' || *str == 'e') {
            ++str;
            flag = isSignedInt(str);
        }
        return flag && (*str == '\0');
    }
    
    bool isUnsignedInt(char *&str) {
        int cnt = 0;
        while(*str != '\0' && *str >= '0' && *str <= '9') {
            ++cnt;
            ++str;
        }
        if(cnt != 0) {
            return true;
        }
        return false;
    }
    
    bool isSignedInt(char *&str) {
        if(*str == '+' || *str == '-') {
            ++str;
        }
        return isUnsignedInt(str);
    }

};