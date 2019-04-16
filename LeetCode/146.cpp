class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> q;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key) != 0){
            q.splice(q.begin(), q, mp[key]);
            return q.begin()->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key) != 0){
            mp[key]->second = value;
            q.splice(q.begin(), q, mp[key]);
        }else{
            q.insert(q.begin(), make_pair(key, value));
            mp[key] = q.begin();
            if(q.size() > _capacity){
                mp.erase(q.back().first);
                q.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */