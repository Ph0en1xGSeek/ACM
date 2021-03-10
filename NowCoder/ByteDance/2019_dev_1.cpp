#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num;
    string str;
    while(cin >> num) {
        while(num--) {
            cin >> str;
            int size = str.size();
            int pos = 0;
            string ans;
            while(pos+2 < size) {
                if(str[pos] != str[pos+1]) {
                    ans += str[pos];
                    ++pos;
                }else {
                    int next = pos + 2;
                    while(next < size && str[next] == str[pos])
                        ++next;
                    int next_next = next + 1;
                    while(next_next < size && str[next_next] == str[next]) 
                        ++next_next;
                    ans += str[pos];
                    ans += str[pos+1];
                    if(next < size) {
                        ans += str[next];
                    }
                    pos = next_next;
                }
            }
            while(pos < size) {
                ans += str[pos];
                ++pos;
            }
            cout << ans << endl;
        }

    }
    return 0;
}