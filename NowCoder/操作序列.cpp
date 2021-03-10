#include <bits/stdc++.h>

using namespace std;



int main()
{
    int num;
    while(cin >> num) {
        vector<int> arr(num, 0);
        for(int i = 0; i < num; ++i) {
            cin >> arr[i];
        }
        if(num & 1) {
            for(int i = num-1; i >= 0; i -= 2) {
                cout << arr[i] << ' ';
            }
            for(int i = 1; i < num; i += 2) {
                cout << arr[i] << ' ';
            }
        }else {
            for(int i = num-1; i >= 0; i -= 2) {
                cout << arr[i] << ' ';
            }
            for(int i = 0; i < num; i += 2) {
                cout << arr[i] << ' ';
            }
        }
    }
    return 0;
}
