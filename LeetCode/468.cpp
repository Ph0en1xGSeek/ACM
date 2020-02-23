class Solution {
public:
    string validIPAddress(string IP) {
        int sz = IP.size();
        bool valid = true;
        if(sz < 6) {
            return "Neither";
        }
        string ans = "IPv4";
        for(int i = 0; i < sz; ++i ) {
            if(IP[i] == ':') {
                ans = "IPv6";
                break;
            }
        }
        int cnt = 0, start = 0, end = 0;
        int num;
        if(ans == "IPv4") {
            while(start < sz) {
                if(cnt > 4) { // invalid group number;
                    valid = false;
                    break;
                }
                while(end < sz && IP[end] != '.') {
                    if(!(IP[end] >= '0' && IP[end] <= '9') || end - start > 3) { //invalid char
                        valid = false;
                        break;
                    }
                    ++end;
                }
                if(!valid) {
                    break;
                }
                if((end > start + 1 && IP[start] == '0') || end == start) { //leading zero or null
                    valid = false;
                    break;
                }
                num = 0;
                for(int i = start; i < end; ++i) {
                    num *= 10;
                    num += IP[i] - '0';
                }
                if(num > 255) {
                    valid = false;
                    break;
                }
                ++cnt;
                start = end = end + 1;
            }
            if(cnt != 4 || IP[sz-1] == '.') { // invalid group number and invalid tail
                valid = false;
            }
        }else {
            while(start < sz) {
                if(cnt > 8) {
                    valid = false;
                    break;
                }
                while(end < sz && IP[end] != ':') {
                    // invalid char
                    if(!((IP[end] >= '0' && IP[end] <= '9') || (IP[end] >= 'a' && IP[end] <= 'f') || (IP[end] >= 'A' && IP[end] <= 'F') ) || end - start > 4) {
                        valid = false;
                        break;
                    }
                    ++end;
                }
                if(!valid) {
                    break;
                }
                if(end == start || end - start > 4) { //null
                    valid = false;
                    break;
                }
                ++cnt;
                start = end = end + 1;
            }
            if(cnt != 8 || IP[sz-1] == ':') {
                valid = false;
            }
        }
        if(valid) {
            return ans;
        }else {
            return "Neither";
        }
    }
};