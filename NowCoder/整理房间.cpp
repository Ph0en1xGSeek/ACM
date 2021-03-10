#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;

    point(int _x, int _y) {
        x = _x;
        y = _y;
    }

    point() {
        x = 0;
        y = 0;
    }

    bool operator<(const point & b) const {
        if(x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }
};

point rotate(point &p, point &from, int time) {
    int x2 = p.x, y2 = p.y;
    for(int i = 0; i < time; ++i) {
        int tmp_x2 = x2;
        x2 = from.x + from.y - y2;
        y2 = tmp_x2 - from.x + from.y;
    }
    return point(x2, y2);
}

int dis(point &p1, point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool isOrthogonal(point &p1, point &p2, point &p3) {
    return ((p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y) == 0);
}

bool isSquare(point p1, point p2, point p3, point p4) {
    vector<point> vec(4);
    vec[0] = p1;
    vec[1] = p2;
    vec[2] = p3;
    vec[3] = p4;
    sort(vec.begin(), vec.end());
    int tmp_dis = dis(vec[0],  vec[1]);
    if(tmp_dis != 0 && dis(vec[0], vec[2]) == tmp_dis && dis(vec[1], vec[3]) == tmp_dis && dis(vec[2], vec[3]) == tmp_dis && isOrthogonal(vec[0], vec[1], vec[2])) {
        return true;
    }else {
        return false;
    }
}

int main() {
    int num;
    point p1, p2, p3, p4;
    point r1, r2, r3, r4;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i) {
        scanf("%d%d%d%d", &p1.x, &p1.y, &r1.x, &r1.y);
        scanf("%d%d%d%d", &p2.x, &p2.y, &r2.x, &r2.y);
        scanf("%d%d%d%d", &p3.x, &p3.y, &r3.x, &r3.y);
        scanf("%d%d%d%d", &p4.x, &p4.y, &r4.x, &r4.y);
        int ans = 100000000;
        for(int m = 0; m < 4; ++m) {
            for(int n = 0; n < 4; ++n) {
                for(int k = 0; k < 4; ++k) {
                    for(int l = 0; l < 4; ++l) {
                        if(isSquare(rotate(p1, r1, m), rotate(p2, r2, n), rotate(p3, r3, k), rotate(p4, r4, l))) {
                            // cout << m << ' ' << n << ' ' << k << ' ' << l << endl;
                            ans = min(ans, m + n + k + l);
                        }
                    }
                }
            }
        }
        if(ans == 100000000) {
            ans = -1;
        }
        printf("%d\n", ans);
    }

    return 0;
}