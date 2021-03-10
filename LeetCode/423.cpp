class Solution {
public:
    string originalDigits(string s) {
        vector<int> ch_cnt(26, 0);
        vector<int> num_cnt(10, 0);
        for(int i = 0; i < s.size(); ++i) {
            ++ch_cnt[s[i] - 'a'];
        }
        for(int i = 0; i < 10; ++i) {
            int cur_num = order[i];
            int cnt = ch_cnt[special_ch[cur_num] - 'a'];
            if(cur_num == 9) {
                cnt /= 2;
            }
            num_cnt[cur_num] += cnt;
            int num_size = num[cur_num].size();
            for(int j = 0; j < num_size; ++j) {
                ch_cnt[num[cur_num][j] - 'a'] -= cnt;
            }
        }
        string ret = "";
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < num_cnt[i]; ++j) {
                ret += num_ch[i];
            }
        }
        return ret;
    }
private:
    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char special_ch[10] = {'z', 'o', 't', 'h', 'r', 'f', 'x', 's', 'g', 'n'};
    int order[10] = {0,8,3,2,6,7,4,5,1,9};
    string num_ch[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
};