#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int main() {
    int num;
    vector<int> arr, crr;
    multiset<int> st;
    int tmp;
    while(~scanf("%d", &num)) {
        st.clear();
        crr.resize(num);
        arr.resize(num);
        for(int i = 0; i < num; ++i) {
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < num; ++i) {
            scanf("%d", &tmp);
            st.insert(tmp);
        }
        for(int i = 0; i < num; ++i) {
            auto it = st.lower_bound(num - arr[i]);
            if(it == st.end()) {
                it = st.begin();
            }
            crr[i] = (arr[i] + (*it)) % num;
            st.erase(it);
        }
        for(int i = 0; i < num; ++i) {
            printf("%d ", crr[i]);
        }
        printf("\n");
    }
    return 0;
}