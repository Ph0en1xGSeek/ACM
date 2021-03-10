class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        int size = operators.size();
        vector<int> ans;
        capacity = k;
        for(int i = 0; i < size; ++i) {
            if(operators[i][0] == 1) {
                put(operators[i][1], operators[i][2]);
            }else {
                ans.push_back(get(operators[i][1]));
            }
        }
        return ans;
    }
    
    int get(int k) {
        if(mp.find(k) == mp.end()) {
            return -1;
        }
        li.splice(li.begin(), li, mp[k]);
        return mp[k]->second;
    }
    
    
    void put(int k, int v) {
        if(mp.find(k) == mp.end()) {
            if(capacity > 0) {
                --capacity;
            }else {
                mp.erase(li.back().first);
                li.pop_back();
            }
            li.push_front(make_pair(k, v));
            mp[k] = li.begin();
        }else {
            get(k);
            mp[k]->second = v;
        }
    }
    
    
    map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> li;
    int capacity;
};
