#include <iostream>
#include <vector>

using namespace std;

struct node {
    int cnt = 0;
    int son[26] = {0};
}arr[10005];

int pos = 0;

void insert(string &str) {
    int cur = 0;
    int size = str.size();
    for(int i = 0; i < size; ++i) {
        int tmp = str[i] - 'a';
        if(arr[cur].son[tmp] == 0) {
            arr[cur].son[tmp] = ++pos;
        }
        cur = arr[cur].son[tmp];
        ++arr[cur].cnt;
    }
}

int search(string &str) {
    int cur = 0;
    int cnt = 0;
    int size = str.size();
    for(int i = 0; i < size; ++i) {
        int tmp = str[i] - 'a';
        cur = arr[cur].son[tmp];
        ++cnt;
        if(arr[cur].cnt == 1) {
            return cnt;
        }
    }
    return size;
}


int main() {
    int n;
    cin >> n;
    vector<string> str(n);
    for(int i = 0; i < n; ++i) {
        cin >> str[i];
        insert(str[i]);
    }
    for(int i = 0; i < n; ++i) {
        int len = search(str[i]);
        cout << str[i].substr(0, len) << endl;
    }
    
    return 0;
}