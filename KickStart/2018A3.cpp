#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <set>
#include <stdio.h>
#define NUM_CHARACTER 26

using namespace std;

struct Key {
    char first;
    char last;
    array<int, NUM_CHARACTER> freq;
    Key(string &s) {
        freq.fill(0);
        first = s[0];
        last = s[s.size()-1];
        for(int j = 0; j < s.size(); ++j) {
            ++freq[s[j] - 'a'];
        }
    }
    bool operator==(const Key &k) const {
        return (first == k.first && last == k.last && freq == k.freq);
    }
};

namespace std {
    template<>
    struct hash<Key> {
        size_t operator()(const Key &k) const {
            size_t ret = 17, seed = 31;
            ret = ret * seed + k.first;
            ret = ret * seed + k.last;
            for(auto item: k.freq) {
                ret = ret * seed + item;
            }
            return ret;
        }
    };
}


int main() {
    int t, l, n;
    long long a, b, c, d;
    char s1, s2;
    string tmp;
    string text;
    scanf("%d", &t);
    unordered_map<Key, int> mp;
    unordered_set<int> len_set;
    vector<int> x;
    for(int ca = 1; ca <= t; ++ca) {
        mp.clear();
        len_set.clear();
        scanf("%d", &l);
        for(int i = 0; i < l; ++i) {
            cin >> tmp;
            len_set.insert(tmp.size());
            Key key(tmp);
            ++mp[key];
        }
        cin >> s1 >> s2;
        cin >> n >> a >> b >> c >> d;
        x.resize(n);
        text.resize(n);
        text[0] = s1;
        text[1] = s2;
        x[0] = text[0];
        x[1] = text[1];
        for(int i = 2; i < n; ++i) {
            x[i] = (a * x[i-1] + b * x[i-2] + c) % d;
            s1 = (97 + (x[i] % 26));
            text[i] = s1;
        }
        int ans = 0;
        for(int len: len_set) {
            if(len > n) {
                continue;
            }
            int l_pos = 0;
            int r_pos = len-1;
            string tmp_str = text.substr(l_pos, len);
            Key len_key(tmp_str);
            while(r_pos < text.size()) {
                auto iter = mp.find(len_key);
                if(iter != mp.end()) {
                    ans += iter->second;
                    mp.erase(iter);
                }
                --len_key.freq[text[l_pos] - 'a'];
                ++l_pos;
                ++r_pos;
                if(r_pos < text.size()) {
                    ++len_key.freq[text[r_pos] - 'a'];
                    len_key.first = text[l_pos];
                    len_key.last = text[r_pos];
                }
            }

        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}