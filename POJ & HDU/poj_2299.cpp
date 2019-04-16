#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 500005

using namespace std;

struct node{
    int num;
    int order;
    bool operator<(const node &b) const{
        return num < b.num;
    }
}arr[M];

int ranks[M];
int cnt[M];
int num;

int lowbit(int x){
    return (x & (-x));
}

void update(int pos, int x){
    while(pos <= num){
        cnt[pos] += x;
        pos += lowbit(pos);
    }
}

int getSum(int pos){
    int ans = 0;
    while(pos >= 1){
        ans += cnt[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

int main(){
    while(~scanf("%d", &num) && num != 0){
        for(int i = 1; i <= num; i++){
            scanf("%d", &arr[i].num);
            arr[i].order = i;
        }
        sort(arr + 1, arr + 1 + num);
        for(int i = 1; i <= num; i++){
            ranks[arr[i].order] = i;
        }
        memset(cnt, 0, sizeof(cnt));
        long long ans = 0;
        for(int i = 1; i <= num; i++){
            update(ranks[i], 1);
            ans += (i - getSum(ranks[i]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
