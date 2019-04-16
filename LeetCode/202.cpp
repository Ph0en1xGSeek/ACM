class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> num_set;
        while(n != 1){
            if(num_set.count(n) != 0){
                return false;
            }
            num_set.insert(n);
            int tmp = 0;
            while(n != 0){
                tmp += (n % 10) * (n  % 10);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};