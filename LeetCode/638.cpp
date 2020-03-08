class Solution {
public:
	int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &need) {
        int sz = price.size();
        if(sz == 0) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < sz; ++i) {
            res += price[i] * need[i];
        }
        int sp_sz = special.size();
        bool isValid = true;
        for(int i = 0; i < sp_sz; ++i) {
            isValid = true;
            for(int j = 0; j < sz; ++j) {
                if(need[j] < special[i][j]) {
                    isValid = false;
                }
                need[j] -= special[i][j];
            }
            if(isValid)
                res = min(res, shoppingOffers(price, special, need) + special[i].back());
            for(int j = 0; j < sz; ++j) {
                need[j] += special[i][j];
            }
        }
        return res;
	}
};