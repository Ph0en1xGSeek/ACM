#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    vector<char> arr(2 * size + 3);
    for(int i = 0; i < size; ++i) {
        arr[(i<<1) + 1] = '#';
        arr[(i<<1) + 2] = str[i];
    }
    arr[2*size + 1] = '#';
    arr[2*size + 2] = '$';
    arr[0] = '&';
    size = 2 * size + 3;
    int bond = -1;
    int id = -1;
    int ans = -1;
    vector<int> dp(size, 0);
    for(int i = 0; i < size; ++i) {
        if(i < bond) {
            dp[i] = min(dp[id + id - i], bond - i);
        }else {
            dp[i] = 1;
        }
        
        while(arr[i - dp[i]] == arr[i + dp[i]]) {
            ++dp[i];
        }
        if(i + dp[i] > bond) {
            bond = i + dp[i];
            id = i;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans-1 << endl;
    return 0;
}