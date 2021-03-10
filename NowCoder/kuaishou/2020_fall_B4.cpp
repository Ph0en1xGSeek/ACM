#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string address;
    int state = 0;
    while(cin >> address) {
        int size = address.size();
        for(int i = 0; i < size; ++i) {
            if(address[i] == ':') {
                state = 1;
                break;
            }else if(address[i] == '.') {
                state = -1;
                break;
            }
        }
        int pos = 0;
        int cnt = 0;
        if(state == -1) {
            int num;
            while(pos < size) {
                if(address[pos] >= '0' && address[pos] <= '9') {
                    char leading = address[pos];
                    ++cnt;
                    if(cnt > 4) {
                        break;
                    }
                    num = 0;
                    while(address[pos] >= '0' && address[pos] <= '9' && num <= 255) {
                        num = num * 10 + address[pos] - '0';
                        ++pos;
                    }
                    if(num > 255 || (pos < size && address[pos] != '.') || (num > 0 && leading == '0')) {
                        state = 0;
                        break;
                    }
                    ++pos;
                }else {
                    state = 0;
                    break;
                }
            }
            if(cnt > 4) {
                state = 0;
            }
        }else if(state == 1) {
            int num;
            while(pos < size) {
                if((address[pos] >= '0' && address[pos] <= '9') || (address[pos] >= 'a' && address[pos] <= 'f') || (address[pos] >= 'A' && address[pos] <= 'F')) {
                    num = 0;
                    ++cnt;
                    if(cnt > 8) {
                        break;
                    }
                    while((address[pos] >= '0' && address[pos] <= '9') || (address[pos] >= 'a' && address[pos] <= 'f') || (address[pos] >= 'A' && address[pos] <= 'F')) {
                        ++num;
                        ++pos;
                        if(num > 4) {
                            break;
                        }
                    }
                    if(num > 4 || (pos < size && address[pos] != ':')) {
                        state = 0;
                        break;
                    }
                    ++pos;
                }else {
                    state = 0;
                    break;
                }
            }
            if(cnt > 8) {
                state = 0;
                break;
            }
        }
        
        if(state == 1) {
            cout << "IPv6" << endl;
        }else if(state == -1) {
            cout << "IPv4" << endl;
        }else {
            cout << "Neither" << endl;
        }
    }
    return 0;
}