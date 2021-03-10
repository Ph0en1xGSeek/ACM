class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
       sz = 0; 
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = v_k.find(val) == v_k.end();
        if(sz >= k_v.size()) {
            k_v.push_back(val);
        }else {
            k_v[sz] = val;
        }
        v_k[val].insert(sz++);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto pos = v_k.find(val);
        bool ret;
        if(pos == v_k.end()) {
            ret = false;
        }else {
            if((pos->second).size() > 0) {
                ret = true;
            }else {
                ret = false;
            }
        }
        if(ret) {
            int delete_k = *((pos->second).begin());
            v_k[val].erase(delete_k);
            int replace_val = k_v[--sz];
            k_v[delete_k] = replace_val;
            v_k[replace_val].erase(sz);
            if(sz != delete_k)
                v_k[replace_val].insert(delete_k);
            
        }
        return ret;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int r = rand() % sz;
        return k_v[r];
    }

private:
    vector<int> k_v;
    unordered_map<int, unordered_set<int>> v_k;
    int sz;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */