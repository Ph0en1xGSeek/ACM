#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
    int m;
    string num;
    int arr[10];
    while(cin >> m >> num) {
        for(int i = 1; i <= 9; ++i) {
            cin >> arr[i];
        }
        bool flag = false;
        for(int i = 0; i < m; ++i) {
            if(arr[num[i] - '0'] > (num[i] - '0')) {
                num[i] = arr[num[i] - '0'] + '0';
                flag = true;
            }else if (arr[num[i] - '0'] == (num[i] - '0')) {
                continue;
            }else if(flag == true) {
                break;
            }
        }
        cout << num << endl;
    } 
    return 0;
}