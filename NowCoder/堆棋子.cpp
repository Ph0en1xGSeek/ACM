#include <bits/stdc++.h>

using namespace std;

struct node{
    int x, y;
};

int main() {
    int num;
    node arr[50];
    while(cin >> num) {
        for(int i = 0; i < num; ++i) {
            cin >> arr[i].x;
        }
        for(int i = 0; i < num; ++i) {
            cin >> arr[i].y;
        }
        vector<vector<int> >dis(num * num);
        for(int i = 0; i < num; ++i) {
            for(int j = 0; j < num; ++j) {
                for(int k = 0; k < num; ++k) {
                    dis[i * num + j].push_back(abs(arr[k].x - arr[i].x) + abs(arr[k].y - arr[j].y));
                }
                sort(dis[i * num + j].begin(), dis[i * num + j].end());
            }
        }
        vector<int> min_dis(num*num, 0);
        for(int i = 0; i < num; ++i) {
            int min_num = INT_MAX;
            for(int j = 0; j < num*num; ++j) {
                min_dis[j] += dis[j][i];
                if(min_num > min_dis[j])
                    min_num = min_dis[j];
            }
            cout << min_num << ' ';
        }
        cout << endl;
    }
    return 0;
}