/**
 * MLE
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <memory>
#include <vector>
#define MAXN 500005
#define MAXM 1000005

using namespace std;

struct point {
    int x;
    int y;
    bool operator<(point b) const {
        if(x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }
};

struct range_tree_node {
    int l;
    int r;
    shared_ptr<range_tree_node> l_child, r_child, father;
    shared_ptr<vector<int>> y;

    range_tree_node(shared_ptr<range_tree_node> _father) {
        l_child = r_child = nullptr;
        father = _father;
    }
};

int T, n, a, b, c, d, e, f, m;

vector<int> px, py, tmpx, tmpy;
shared_ptr<range_tree_node> dest[MAXN];
vector<shared_ptr<range_tree_node> >xnode_before;

void build_range_xtree(shared_ptr<range_tree_node> &node, shared_ptr<range_tree_node> father, int l, int r) {
    if(l >= r) {
        return;
    }
    node = make_shared<range_tree_node>(father);
    node->l = px[l];
    node->r = px[r-1];
    int pos = 0;
    tmpx[pos++] = px[l];
    for(int i = l+1; i < r; ++i) {
        if(px[i] != px[i-1])
            tmpx[pos++] = px[i];
    }
    int node_mid = tmpx[(pos-1) >> 1];
    if(pos > 1) {
        int mid = l;
        for(int i = l; i < r; ++i) {
            if(px[i] <= node_mid) {
                mid = i;
            }else {
                break;
            }
        }
        build_range_xtree(node->l_child, node, l, mid+1);
        build_range_xtree(node->r_child, node, mid+1, r);
        
        // for(int i = l; i < r; ++i) {
        //     tmpy[i] = py[i];
        // }
        // pos = l;
        // int p1 = l, p2 = mid+1;
        // while(p1 < mid+1 || p2 < r) {
        //     if(p1 >= mid + 1) {
        //         py[pos++] = tmpy[p2++];
        //     }else if(p2 >= r) {
        //         py[pos++] = tmpy[p1++];
        //     }else if(tmpy[p1] <= tmpy[p2]) {
        //         py[pos++] = tmpy[p1++];
        //     }else {
        //         py[pos++] = tmpy[p2++];
        //     }
        // }
    } else {
        node->y = make_shared<vector<int>>(py.begin() + l, py.begin() + r);
        dest[l] = node;
    }
}

inline int greater_cnt(const vector<int> &vec, int num) {
    return vec.end() - upper_bound(vec.begin(), vec.end(), num);
}

inline int less_cnt(const vector<int> &vec, int num) {
    return lower_bound(vec.begin(), vec.end(), num) - vec.begin();
}

int main() {
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        vector<point> p(n);
        px.resize(n);
        py.resize(n);
        tmpx.resize(n);
        tmpy.resize(n);
        scanf("%d%d%d%d%d%d%d%d%d", &p[0].x, &p[0].y, &a, &b, &c, &d, &e, &f, &m);
        for(int i = 1; i < n; ++i) {
            p[i].x = ((long long)a * p[i-1].x + (long long)b * p[i-1].y + c) % m;
            p[i].y = ((long long)d * p[i-1].x + (long long)e * p[i-1].y + f) % m;
        }
        sort(p.begin(), p.end());
        for(int i = 0; i < n; ++i) {
            px[i] = p[i].x;
            py[i] = p[i].y;
        }
        shared_ptr<range_tree_node> root;
        build_range_xtree(root, nullptr, 0, n);
        sort(py.begin(), py.end());

        long long ans = (long long)n * (n - 1) * (n - 2) / 3 / 2;
        int n1, n2, n3, n4;
        xnode_before.clear();
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && p[j].x == p[i].x)
                ++j;
            for(int k = i; k < j; ++k) {
                n2 = n3 = 0;
                for(int l = 0; l < xnode_before.size(); ++l) {
                    n2 += greater_cnt(*(xnode_before[l]->y), p[k].y);
                    n3 += less_cnt(*(xnode_before[l]->y), p[k].y);
                }
                n1 = greater_cnt(py, p[k].y) - n2 - (j - k - 1);
                n4 = less_cnt(py, p[k].y) - n3 - (k - i);
                ans -= (long long )(n1 * n3) + (long long)(n2 * n4);
            }
            xnode_before.push_back(dest[i]);
            while(xnode_before.size() >= 2 && xnode_before[xnode_before.size() - 1]->father == xnode_before[xnode_before.size() - 2]->father) {


                int sz = xnode_before.size();
                int sz1 = xnode_before[sz - 1]->y->size();
                int sz2 = xnode_before[sz - 2]->y->size();
                xnode_before[sz - 1]->father->y = make_shared<vector<int>>(sz1 + sz2, 0);

                int pos = 0;
                int p1 = 0, p2 = 0;
                while(p1 < sz1 || p2 < sz2) {
                    if(p1 >= sz1) {
                        (*(xnode_before[sz - 1]->father->y))[pos++] = (*(xnode_before[sz - 2]->y))[p2++];
                    }else if(p2 >= sz2) {
                        (*(xnode_before[sz - 1]->father->y))[pos++] = (*(xnode_before[sz - 1]->y))[p1++];
                    }else if((*(xnode_before[sz - 1]->y))[p1] <= (*(xnode_before[sz - 2]->y))[p2]) {
                        (*(xnode_before[sz - 1]->father->y))[pos++] = (*(xnode_before[sz - 1]->y))[p1++];
                    }else {
                        (*(xnode_before[sz - 1]->father->y))[pos++] = (*(xnode_before[sz - 2]->y))[p2++];
                    }
                }
                xnode_before[sz - 1]->y = nullptr;
                xnode_before[sz - 2]->y = nullptr;
                xnode_before[sz - 2] = xnode_before[sz - 2]->father;
                xnode_before.pop_back();
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}