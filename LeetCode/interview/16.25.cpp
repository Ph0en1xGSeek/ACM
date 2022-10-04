class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {
        
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            q.splice(q.begin(), q, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            q.splice(q.begin(), q, mp[key]);
            mp[key]->second = value;
        }else {
            q.push_front(make_pair(key, value));
            mp[key] = q.begin();
            if(q.size() > _capacity) {
                int delete_key = q.back().first;
                q.pop_back();
                mp.erase(delete_key);
            }
        }
    }
private:
    int _capacity;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> q;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */