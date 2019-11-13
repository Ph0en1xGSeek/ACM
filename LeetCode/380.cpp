class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        sz = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(v_k.find(val) != v_k.end()) {
            return false;
        }
        k_v[sz] = val;
        v_k[val] = sz++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(v_k.find(val) != v_k.end()) {
            int delete_size = v_k[val];
            int last_v = k_v[sz-1];
            k_v[delete_size] = last_v;
            v_k[last_v] = delete_size;
            --sz;
            v_k.erase(val);
            k_v.erase(sz);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % sz;
        return k_v[r];
    }

private:
    unordered_map<int, int> k_v;
    unordered_map<int, int> v_k;
    int sz;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */