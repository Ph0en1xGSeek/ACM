class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = candies.size();
        vector<bool> answer;
        int max_candies = 0;
        for (int i = 0; i < size; ++i) {
            max_candies = max(max_candies, candies[i]);
        }
        for (int i = 0; i < size; ++i) {
            answer.push_back(candies[i] + extraCandies >= max_candies);
        }
        return answer;
    }
};