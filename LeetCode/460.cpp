class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        freq[mp[key].second].erase(iter[key]);
        ++mp[key].second;
        freq[mp[key].second].push_back(key);
        iter[key] = --freq[mp[key].second].end();
        while(freq[minFreq].size() == 0) {
            ++minFreq;
        }
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(cap <= 0) {
            return;
        }
        if(get(key) != -1) {
            mp[key].first = value;
            return;
        }
        if(mp.size() >= cap) {
            auto delete_iter = freq[minFreq].begin();
            int delete_key = *delete_iter;
            mp.erase(mp.find(delete_key));
            iter.erase(iter.find(delete_key));
            freq[minFreq].erase(delete_iter);
        }
        mp[key] = make_pair(value, 1);
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    unordered_map<int, pair<int, int> > mp;
    unordered_map<int, list<int>>freq;
    unordered_map<int, list<int>::iterator> iter;
    int cap;
    int minFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */