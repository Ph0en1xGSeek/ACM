#include <iostream>
#include <vector>

using namespace std;

void build(vector<int> &preorder, int pre_from, int pre_to,
          vector<int> &inorder, int in_from, int in_to,
          vector<int> &postorder, int post_from, int post_to) {
    if(pre_from > pre_to) {
        return;
    }
    if(pre_from == pre_to) {
        postorder[post_from] = preorder[pre_from];
        return;
    }
    int pos;
    for(pos = in_from; preorder[pre_from] != inorder[pos] && pos <= in_to; ++pos);
    build(preorder, pre_from+1, pre_from + pos - in_from,
         inorder, in_from, pos-1,
         postorder, post_from, post_from + pos - in_from - 1);
    build(preorder, pre_from + pos - in_from + 1, pre_to,
         inorder, pos+1, in_to,
         postorder, post_from + pos - in_from, post_to-1);
    postorder[post_to] = preorder[pre_from];
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    for(int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    vector<int> postorder(n);
    build(preorder, 0, n-1,
         inorder, 0, n-1,
         postorder, 0, n-1);
    for(int i = 0; i < n; ++i) {
        cout << postorder[i] << " ";
    }
    cout << endl;
    return 0;
}