#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int pos;
    bool isLeft;
    int height;
    node(): pos(0), isLeft(false), height(0) {}
    bool operator<(const node &b) {
        return pos < b.pos;
    }
};

int main() {
    int num;
    cin >> num;
    vector<node> arr(num * 2);
    for(int i = 0; i < num; ++i) {
        for(int i = 0; i < num; ++i) {
            scanf("%d", &arr[i<<1].pos);
            scanf("%d", &arr[(i<<1) + 1].pos);
            scanf("%d", &arr[i<<1].height);
            arr[(i<<1)+1].height = arr[i<<1].height;
            arr[i<<1].isLeft = true;
        }
    }
    sort(arr.begin(), arr.end());
    int tmp = 0;
    int pre_height = 0;
    int pre_pos = -1;
    map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < num * 2;) {
        tmp = arr[i].pos;
        while(i < num * 2 && arr[i].pos == tmp) {
            if(arr[i].isLeft) {
                if(mp.find(arr[i].height) == mp.end()) {
                    mp[arr[i].height] = 1;
                }else {
                    ++mp[arr[i].height];
                }
            }else if(--mp[arr[i].height] == 0){
                mp.erase(arr[i].height);
            }
            ++i;
        }
        int height = (--mp.end())->first;
        if(pre_height != 0 && height != pre_height) {
            printf("%d %d %d\n", pre_pos, tmp, pre_height);
        }
        if(height != pre_height) {
            pre_height = height;
            pre_pos = tmp;
        }
    }
    return 0;
}