#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFU {
public:
    LFU(int cap_): minFreq(0), cap(cap_){}
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        int cur_freq = mp[key].second;
        int value = mp[key].first;
        ++(mp[key].second);
        freq[cur_freq].erase(iter[key]);
        freq[cur_freq+1].push_back(key);
        iter[key] = --freq[cur_freq+1].end();
        if(freq[cur_freq].size() == 0) {
            ++minFreq;
        }
        return value;
    }
    
    void set(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key].first = value;
            int cur_freq = mp[key].second;
            ++(mp[key].second);
            freq[cur_freq].erase(iter[key]);
            freq[cur_freq + 1].push_back(key);
            iter[key] = --freq[cur_freq + 1].end();
            if(freq[minFreq].size() == 0) {
                ++minFreq;
            }
        }else {
            if(cap == 0) {
                int delete_key = *(freq[minFreq].begin());
                freq[minFreq].erase(freq[minFreq].begin());
                mp.erase(mp.find(delete_key));
                iter.erase(iter.find(delete_key));
            }else {
                --cap;
            }
            minFreq = 1;
            mp[key] = {value, 1};
            freq[1].push_back(key);
            iter[key] = --freq[1].end();
        }
    }
    
private:
    unordered_map<int, pair<int, int>> mp;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
    int minFreq;
    int cap;
};

int main() {
    int n, k;
    int operation, key, value;
    cin >> n >> k;
    LFU cache(k);
    for(int i = 0; i < n; ++i) {
        cin >> operation;
        if(operation == 1) {
            cin >> key >> value;
            cache.set(key, value);
        }else {
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }
    return 0;
}