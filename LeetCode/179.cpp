class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return "";
        }
        vector<string> str_nums(sz);
        for(int i = 0; i < sz; ++i) {
            int tmp = nums[i];
            if(tmp == 0) {
                str_nums[i] = "0";
            }else {
                while(tmp > 0) {
                    int bit = tmp % 10;
                    tmp /= 10;
                    str_nums[i] += ('0' + bit);
                }
                reverse(str_nums[i].begin(), str_nums[i].end()); 
            }
        }
        sort(str_nums.begin(), str_nums.end(), [](const string &a, const string &b) -> bool {
            return a+b > b+a;
        });
        string res = "";
        if(str_nums[0] == "0") {
            return "0";
        }
        for(string str: str_nums) {
            res += str;
        }
        return res;
    }
};