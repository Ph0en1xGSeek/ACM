#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 202

using namespace std;

struct node{
	double x;
	double y;
}stones[MAX];

double arr[MAX][MAX];

int main(){

	int num;
	int ca = 1;
	while(~scanf("%d", &num) && num != 0){
		for(int i = 0; i < num; i++){
			scanf("%lf%lf", &stones[i].x, &stones[i].y);
		}
		for(int i = 0; i < num; i++){
            arr[i][i] = 0;
			for(int j = i+1; j < num; j++){
				arr[i][j] = arr[j][i] = sqrt((stones[i].x - stones[j].x)*(stones[i].x - stones[j].x) + (stones[i].y - stones[j].y)*(stones[i].y - stones[j].y));
			}
		}
		for(int k = 0; k < num; k++){
			for(int i = 0; i < num; i++){
				for(int j = 0; j < num; j++){
					arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
				}
			}
		}
		printf("Scenario #%d\n", ca++);
		printf("Frog Distance = %.3f\n\n", (arr[0][1]));
	}
    return 0;
}
