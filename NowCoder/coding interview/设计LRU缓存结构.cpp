#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRU {
public:
    int get(int x) {
        if(key.find(x) == key.end()) {
            return -1;
        }else {
            value.splice(value.begin(), value, key[x]);
            return key[x]->second;
        }
    }
    
    void set(int x, int y) {
        if(key.find(x) == key.end()) {
            value.insert(value.begin(), {x, y});
            key[x] = value.begin();
            --capacity;
            if(capacity < 0) {
                ++capacity;
                key.erase(value.back().first);
                value.pop_back();
            }
        }else {
            value.splice(value.begin(), value, key[x]);
            key[x]->second = y;
        }
    }
    LRU(int _capacity): capacity(_capacity) {}
private:
    unordered_map<int, list<pair<int, int>>::iterator> key;
    list<pair<int, int>> value;
    int capacity;
};

int main() {
    int n, c;
    int op, x, y;
    while(cin >> n >> c) {
        LRU lru(c);
        for(int i = 0; i < n; ++i) {
            cin >> op;
            if(op == 1) {
                cin >> x >> y;
                lru.set(x, y);
            }else {
                cin >> x;
                cout << lru.get(x) << endl;
            }
        }
    }
    return 0;
}