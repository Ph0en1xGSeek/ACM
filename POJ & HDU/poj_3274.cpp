#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

#define N 100010
#define K 32
#define HASH 100000

using namespace std;

struct node{
    int index;
    int num[K];
};

vector<node> table[HASH];
int sum[K];

int main(){
    int n, k, feature, hash, ans;
    node tmp;
    while(~scanf("%d%d", &n, &k)){
        memset(sum, 0, sizeof(sum));
        memset(tmp.num, 0, sizeof(tmp.num));
        ans = 0;
        tmp.index = 0;
        for(int i = 0; i < HASH; i++){
            table[i].clear();
        }
        table[0].push_back(tmp);
        for(int i = 1; i <= n; i++){
            hash = 0;
            scanf("%d", &feature);
            for(int j = 0; j < k; j++){
                if((feature >> j) & 1){
                    sum[j]++;
                }
                if(j > 0){
                    tmp.num[j] = sum[j] - sum[0];
                    hash += tmp.num[j] * j;
                }
            }
            tmp.index = i;
            hash = abs(hash) % HASH;
            for(int j = 0; j < table[hash].size(); j++){
                bool flag = true;
                for(int l = 0; l < k; l++){
                    if(table[hash][j].num[l] != tmp.num[l]){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    ans = max(ans, tmp.index - table[hash][j].index);
                }
            }
            table[hash].push_back(tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
