class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        int size_2 = arr2.size();
        for (int i = 0; i < size_2; ++i) {
            rank[arr2[i]] = i;
        }

        auto gen_pair = [&](int x) -> pair<int, int> {
            return rank.find(x) != rank.end() ? pair{0, rank[x]} : pair{1, x};
        };
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            return gen_pair(x) < gen_pair(y);
        });
        return arr1;
    }
};