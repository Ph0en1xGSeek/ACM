
struct Node {
    int num;
    int times;
    Node(int _num, int _times) {
        num = _num;
        times = _times;
    }
    
    bool operator<(const Node &b) const {
        if(times == b.times) {
            return num > b.num;
        }
        return times > b.times;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int sz = nums.size();
        if(sz == k) {
            return nums;
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < sz; ++i) {
            ++mp[nums[i]];
        }
        vector<Node> cnt;
        for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
            cnt.push_back(Node(iter->first, iter->second));
        }
        sort(cnt.begin(), cnt.end());
        int i;
        for(i = 0; i < k; ++i) {
            ans.push_back(cnt[i].num);
        }
        // while(i < sz && cnt[i].times == cnt[i-1].times) {
        //     ans.push_back(cnt[i++].num);
        // }
        return ans;
    }
};
