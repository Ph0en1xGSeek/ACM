#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#define MAX 501

using namespace std;

int arr[MAX][MAX];
bool vis[MAX];
int ca, num;

struct node{
	int num;
	int v;
	bool operator<(const node &b) const{
		return v > b.v;
	}
};

int prim(int start){
	int ans = 0;
	priority_queue<node> q;
	memset(vis, false, sizeof(vis));
	node tmp;
	tmp.num = start;
	tmp.v = 0;
	q.push(tmp);
	for(int k = 0; k < num; k++){
		node cur;
		do{
			cur = q.top();
			q.pop();
		}while(vis[cur.num]);
		vis[cur.num] = true;
		ans = max(ans, cur.v);
		for(int i = 0; i < num; i++){
			if(!vis[i] && arr[cur.num][i] > 0){
				node tmp;
				tmp.num = i;
				tmp.v = arr[cur.num][i];
				q.push(tmp);
			}
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d", &ca)){
		while(ca--){
			scanf("%d", &num);
			for(int i = 0; i < num; i++){
				for(int j = 0; j < num; j++){
					scanf("%d", &arr[i][j]);
				}
			}
			int ans = prim(0);
			printf("%d\n", ans);
		}
	}
    return 0;
}
