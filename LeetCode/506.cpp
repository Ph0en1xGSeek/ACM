struct node{
    int index;
    int num;
};

class Solution {
public:
    string num2str(int num) {
        if(num == 0) {
            return "0";
        }
        string str;
        while(num > 0) {
            int tmp = num % 10;
            str.push_back(tmp + '0');
            num /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size = nums.size();
        vector<node> arr(size);
        for(int i = 0; i < size; ++i) {
            arr[i].index = i;
            arr[i].num = nums[i];
        }
        sort(arr.begin(), arr.end(), [](const node &a, const node &b){
            return a.num > b.num;
        });
        vector<string> ans(size);
        for(int i = 0; i < size; ++i) {
            if(i == 0) {
                ans[arr[i].index] = "Gold Medal";
            }else if(i == 1) {
                ans[arr[i].index] = "Silver Medal";
            }else if(i == 2) {
                ans[arr[i].index] = "Bronze Medal";
            }else {
                ans[arr[i].index] = num2str(i + 1);
            }
        }
        return ans;
    }
};
