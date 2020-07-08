#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    vector<int> clear_item;
    vector<int> arr(n);
    for(int i = 0 ; i < n; ++i) {
        cin >> arr[i];
        if(mp.find(arr[i]) != mp.end()) {
            ++mp[arr[i]];
        }else {
            if(mp.size() == k - 1) {
                clear_item.clear();
                for(unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
                    if(iter->second == 1) {
                        clear_item.push_back(iter->first);
                    }
                }
                for(int item: clear_item) {
                    mp.erase(item);
                }
            }else {
                mp[arr[i]] = 1;
            }
        }
    }
    for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
        iter->second = 0;
    }
    for(int i = 0; i < n; ++i) {
        if(mp.find(arr[i]) != mp.end()) {
            ++mp[arr[i]];
        }
    }
    bool flag = false;
    for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
        if(iter->second > n / k) {
            flag = true;
            cout << iter->first << " ";
        }
    }
    if(flag == false) {
        cout << -1;
    }
    cout << endl;
    return 0;
}