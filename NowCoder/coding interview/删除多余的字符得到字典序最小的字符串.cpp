#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    vector<bool> exist(128);
    vector<int> cnt(128, 0);
    int output_size = 0;
    for(int i = 0; i < size; ++i) {
        ++cnt[str[i]];
        if(!exist[str[i]]) {
            ++output_size;
            exist[str[i]] = true;
        }
    }
    vector<char> output(output_size);
    int pos = 0;
    for(int i = 0; i < size; ++i) {
        if(!exist[str[i]]) {
            --cnt[str[i]];
            continue;
        }
        while(pos > 0 && output[pos-1] > str[i] && cnt[output[pos-1]] > 0) {
            exist[output[pos-1]] = true;
            --pos;
        }
        output[pos++] = str[i];
        exist[str[i]] = false;
        --cnt[str[i]];
    }
    for(int i = 0; i < output_size; ++i) {
        cout << output[i];
    }
    cout << endl;
    return 0;
}