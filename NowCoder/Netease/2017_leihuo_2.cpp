#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    vector<int> accu(n+1, 0);
    accu[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            accu[j+1] = arr[i][j] + accu[j];
            if(j+1 >= k)
                ans = max(ans, accu[j+1] - accu[j+1-k]);
        }
    }
    
    for(int j = 0; j < n; ++j) {
        for(int i = 0; i < n; ++i) {
            accu[i+1] = arr[i][j] + accu[i];
            if(i+1 >= k)
                ans = max(ans, accu[i+1] - accu[i+1-k]);
        }
    }
    
    for(int j = 0; j < n; ++j) {
        int i = 0;
        int y = j;
        while(i < n && y < n) {
            accu[i+1] = arr[i][y] + accu[i];
            if(i+1 >= 0)
                ans = max(ans, accu[i+1] - accu[i+1-k]);
            ++i;
            ++y;
        }
    }
    
    for(int j = 1; j < n; ++j) {
        int i = 0;
        int y = j;
        while(i < n && y < n) {
            accu[i+1] = arr[y][i] + accu[i];
            if(i+1 >= 0)
                ans = max(ans, accu[i+1] - accu[i+1-k]);
            ++i;
            ++y;
        }
    }
    
    for(int j = 0; j < n; ++j) {
        int i = 0;
        int y = j;
        while(i < n && y >= 0) {
            accu[i+1] = arr[i][y] + accu[i];
            if(i+1 >= k)
                ans = max(ans, accu[i+1] - accu[i+1-k]); 
            ++i;
            --y;
        }
    }
    for(int j = 1; j < n; ++j) {
        int i = n-1;
        int y = j;
        while(i >= 0 && y < n) {
            accu[n-i] = arr[y][i] + accu[n-i-1];
            if(n-i >= k)
                ans = max(ans, accu[n-i] - accu[n-i-k]); 
            --i;
            ++y;
        }
    }
    cout << ans << endl;
    return 0;
}