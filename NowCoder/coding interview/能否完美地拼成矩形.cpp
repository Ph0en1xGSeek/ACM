#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int num;
    long long x1, y1, x2, y2;
    long long xmx = -1, ymx = -1, xmi = 1000000, ymi = 1000000;
    long long area = 0;
    cin >> num;
    vector<vector<int>> arr(num, vector<int>(4));
    for(int i = 0; i < num; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    unordered_map<long long, int> mp;
    for(int i = 0; i < num; ++i) {
        x1 = arr[i][0];
        y1 = arr[i][1];
        x2 = arr[i][2];
        y2 = arr[i][3];
        if(xmx <= x2 && ymx <= y2) {
            xmx = x2;
            ymx = y2;
        }
        if(xmi >= x1 && ymi >= y1) {
            xmi = x1;
            ymi = y1;
        }
        ++mp[(x1 << 20) + y1];
        ++mp[(x1 << 20) + y2];
        ++mp[(x2 << 20) + y1];
        ++mp[(x2 << 20) + y2];
        area += (x2 - x1) * (y2 - y1);
    }
    if(area != (xmx - xmi) * (ymx - ymi)) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < num; ++i) {
        if(arr[i][0] < xmi || arr[i][1] < ymi || arr[i][2] > xmx || arr[i][3] > ymx) {
            cout << "No" << endl;
            return 0;
        }
    }
    int cnt = 0;
    bool flag = true;
    for(auto iter: mp) {
        if(iter.second == 1) {
            ++cnt;
            if(cnt > 4) {
                flag = false;
                break;
            }
        }else if(iter.second % 2 != 0) {
            flag = false;
            break;
        }
    }
    if(cnt != 4) {
        flag = false;
    }
    if(flag) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}