class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int size = height.size();
        if(size == 0) {
            return 0;
        }
        vector<pair<int, int>> man(size);
        for(int i = 0; i < size; ++i) {
            man[i].first = height[i];
            man[i].second = weight[i];
        }
        sort(man.begin(), man.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        vector<pair<int, int>> arr;
        for(int i = 0; i < size; ++i) {
            int l = 0, r = arr.size() - 1;
            while(l <= r) {
                int mid = l + ((r - l) >> 1);
                if(arr[mid].first < man[i].first && arr[mid].second < man[i].second) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
            if(l == arr.size()) {
                arr.push_back({man[i].first, man[i].second});
            }else {
                arr[l].first = man[i].first;
                arr[l].second = man[i].second;
            }
        }
        return arr.size();
    }
};