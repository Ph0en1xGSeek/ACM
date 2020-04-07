#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ca;
    long long n, tmp, sum;
    bool flag;
    cin >> ca;
    while(ca--) {
        flag = true;
        cin >> n >> sum;
        for(long long i = 0; i < n; ++i) {
            cin >> tmp;
            if(flag) {
                if(tmp > i) {
                    sum += (tmp - i);
                }else {
                    if(sum < i - tmp) {
                        flag = false;
                    }else {
                        sum -= (i - tmp);
                    }
                }
            }
        }
        if(flag) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}