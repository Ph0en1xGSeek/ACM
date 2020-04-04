#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int arr[152];

int lowbit(int x) {
    return x & (-x);
}

int getSum(int x) {
    int sum = 0;
    while(x > 0) {
        sum += arr[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(int x) {
    while(x <= 151) {
        arr[x] += 1;
        x += lowbit(x);
    }
}

int main() {
    int n, tmp, q, ans;
    while(cin >> n) {
        memset(arr, 0, sizeof(arr));
        vector<int> student(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            cin >> student[i];
            add(student[i]+1);
        }
        
        cin >> q;
        for(int i = 0; i < q; ++i) {
            cin >> tmp;
            ans = getSum(student[tmp]+1);
            printf("%.6lf\n",((double)ans - 1) * 100.0 / n);
        }
    }
    return 0;
}


#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main() {
    int num, q, tmp;
    cin >> num;
    vector<int> cnt(151, 0);
    vector<int> arr(num, 0);
    for(int i = 0; i < num; ++i) {
        cin >> arr[i];
        ++cnt[arr[i]];
    }
    for(int i = 1; i <= 150; ++i) {
        cnt[i] += cnt[i-1];
    }
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> tmp;
        printf("%.6lf\n", ((double)cnt[arr[tmp-1]] - 1.0) / num * 100);
    }
    return 0;
}