#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

struct file{
    int cnt;
    int id;
    string filename;
    string line;
    bool operator<(const file &f) const{
        if(cnt == f.cnt) {
            return id < f.id;
        }else {
            return cnt > f.cnt;
        }
    }
};

int main() {
    int cnt = 0;
    string filePath;
    string line;
    unordered_map<string, int> mp;
    vector<file> vf;
    while(cin >> filePath >> line) {
        ++cnt;
        // if(cnt > 8) {
        //     break;
        // }
        
        int size = filePath.size();
        int start = max(size - 16, 0);
        for(int i = start; i < size; ++i) {
            if(filePath[i] == '\\') {
                start = i+1;
            }
        }
        string fileName = filePath.substr(start, size - start);
        string fullName = fileName + "@" + line;
        if(mp.find(fullName) != mp.end()) {
            ++vf[mp[fullName]].cnt;
        }else {
            mp[fullName] = vf.size();
            file f;
            f.cnt = 1;
            f.id = mp[fullName];
            f.filename = fileName;
            f.line = line;
            vf.push_back(f);
        }
    }
    sort(vf.begin(), vf.end());
    for(int i = 0; i < min(8, (int)vf.size()); ++i) {
        cout << vf[i].filename << " " << vf[i].line << " " << vf[i].cnt << endl;
    }
    return 0;
}