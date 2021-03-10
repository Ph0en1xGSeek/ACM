#include <iostream>
#include <vector>

using namespace std;

struct node {
    vector<int> ch;
    int fa;
    int val;
    node(): fa(0), val(0){}
};

void clear(vector<node> &tree, int id) {
    while(id != 0 && tree[id].val == 1) {
        tree[id].val = 0;
        id = tree[id].fa;
    }
}

void set(vector<node> &tree, int id) {
    if(tree[id].val == 1) {
        return;
    }
    tree[id].val = 1;
    int size = tree[id].ch.size();
    for(int i = 0; i < size; ++i) {
        set(tree, tree[id].ch[i]);
    }
}

int main() {
    int n, a, b, q;
    cin >> n;
    vector<node> tree(n+1);
    for(int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        if(a > b) {
            swap(a, b);
        }
        tree[a].ch.push_back(b);
        tree[b].fa = a;
    }
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        if(a == 1) {
            set(tree, b);
        }else if(a == 2) {
            clear(tree, b);
        }else {
            cout << tree[b].val << endl;
        }
    }
    return 0;
}