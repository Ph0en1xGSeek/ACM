#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > mi;
priority_queue<int, vector<int>, less<int> > mx;
int mid;


int main(){
    int ca, tmp;
    while(!mi.empty())
        mi.pop();
    while(!mx.empty())
        mx.pop();
    scanf("%d%d", &ca, &mid);
    ca--;
    while(ca--){
        scanf("%d", &tmp);
        if(tmp < mid){
            mx.push(tmp);
        }else{
            mi.push(tmp);
        }
        if(mi.size() >= mx.size() + 2){
            mx.push(mid);
            mid = mi.top();
            mi.pop();
        }else if(mx.size() >= mi.size() + 2){
            mi.push(mid);
            mid = mx.top();
            mx.pop();
        }
    }
    printf("%d\n", mid);

    return 0;
}
