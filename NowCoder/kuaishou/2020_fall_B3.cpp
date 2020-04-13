#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, string> mp;
int size;
bool first;

void dfs(string &str, int pos, string cur) {
    if(pos == size) {
        if(first) {
            first = false;
            cout << '[' + cur;
        }else {
            cout << ", " << cur; 
        }
        return;
    }
    int s_size = mp[str[pos]].size();
    for(int i = 0; i < s_size; ++i) {
        dfs(str, pos+1, cur + mp[str[pos]][i]);
    }
}

int main() {
    string input;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    while(cin >> input) {
        size = input.size();
        first = true;
        dfs(input, 0, "");
        cout << ']' << endl;
    }
    return 0;
}