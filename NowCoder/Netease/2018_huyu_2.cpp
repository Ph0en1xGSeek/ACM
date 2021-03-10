#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class SessionList{
public:
    void insert(int num) {
        auto iter = mp.find(num);
        if(iter != mp.end()) {
            li.splice(li.begin(), li, iter->second);
        }else {
            li.insert(li.begin(), num);
            mp[num] = li.begin();
        }
    }
    
    void print() {
        for(auto iter = li.begin(); iter != li.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
private:
    unordered_map<int, list<int>::iterator> mp;
    list<int> li;
};

int main() {
    int ca, num, tmp;
    cin >> ca;
    while(ca--) {
        SessionList sl;
        cin >> num;
        for(int i = 0; i < num; ++i) {
            cin >> tmp;
            sl.insert(tmp);
        }
        sl.print();
    }
    return 0;
}