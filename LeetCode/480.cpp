class Solution {
public:
    void add(multiset<int> &small, multiset<int> &big, int num) {
        if(!small.empty() && num <= *(small.rbegin())) {
            small.insert(num);
        }else if(!big.empty() && num >= *(big.begin())) {
            big.insert(num);
        }else {
            small.insert(num);
        }
        balance(small, big);
    }
    
    void del(multiset<int> &small, multiset<int> &big, int num) {
        if(small.find(num) != small.end()) {
            small.erase(small.find(num));
        }else if(big.find(num) != big.end()){
            big.erase(big.find(num));
        }
        balance(small, big);
    }
    
    double getMedian(multiset<int> &small, multiset<int> &big) {
        if(small.size() > big.size()) {
            return *(small.rbegin());
        }else if(big.size() > small.size()) {
            return *(big.begin());
        }else {
            return ((double)*(small.rbegin()) + *(big.begin())) / 2;
        }
    }
    
    void balance(multiset<int> &small, multiset<int> &big) {
        int cnt_small = small.size();
        int cnt_big = big.size();
        if(cnt_small > cnt_big + 1) {
            int tmp = *(small.rbegin());
            small.erase(--small.end());
            big.insert(tmp);
        }else if(cnt_big > cnt_small + 1) {
            int tmp = *(big.begin());
            big.erase(big.begin());
            small.insert(tmp);
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        int cnt_mi = 0;
        int cnt_mx = 0;
        multiset<int> small;
        multiset<int> big;
        vector<double> ans;
        for(int i = 0; i < k-1; ++i) {
            add(small, big, nums[i]);
        }
        for(int i = k-1; i < size; ++i) {
            add(small, big, nums[i]);
            ans.push_back(getMedian(small, big));
            del(small, big, nums[i-k+1]);
        }
        return ans;
    }
};