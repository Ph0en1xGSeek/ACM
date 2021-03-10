#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
int main() {
    int ca, num;
    int sum;
    cin >> ca;
    while(ca--) {
        sum = 0;
        for(int i = 0; i < 5; ++i) {
            cin >> num;
            sum += num;
        }
        if(sum != 0 && sum % 5 == 0) {
            cout << sum / 5 << endl;
        }else {
            cout << -1 << endl;
        }
    }
    return 0;
}