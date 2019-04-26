#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

int main()
{
    int num;
    int tmp;
    map<int, bool> mp;
    unordered_set<int> st;
    int ans;
    while(~scanf("%d", &num)) {
        ans = 100001;
        mp.clear();
        mp[0] = true;
        for(int i = 0; i < num; ++i) {
            st.clear();
            scanf("%d", &tmp);
            for(auto item: mp) {
                st.insert(item.first + tmp);
            }
            for(auto item: st) {
                mp[item] = true;
            }
        }
        for(int i = 1; i <= (1<<20); ++i) {
            if(mp.find(i) == mp.end()) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
