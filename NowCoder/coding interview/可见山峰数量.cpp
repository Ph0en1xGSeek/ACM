#include <iostream>

using namespace std;

int main() {
    int ca, n, p, m;
    cin >> ca;
    while(ca--) {
        cin >> n >> p >> m;
        if(n == 1) {
            cout << 0 << endl;
        }else {
            cout << 2 * n - 3 << endl;
        }
    }
    return 0;
}
/*
每个山峰都向左和向右找第一个比自己大的山峰
最大的找不到可见山峰对
次大的只能找到一个
其他可以找到两个
如果只有一座山 为0
*/