#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct robot{
    int x;
    int y;
    int dir;
}robots[101];

int main(){
    int ca;
    int num, step;
    int A, B, N, M;
    char tmp;
    int arr[101][101];
    bool flag;
    scanf("%d", &ca);
    while(ca--){
        flag = true;
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d%d", &A, &B, &N, &M);
        for(int i = 1; i <= N; i++){
            scanf("%d%d", &robots[i].x, &robots[i].y);
            arr[robots[i].x][robots[i].y] = i;
            getchar();
            scanf("%c", &tmp);
            if(tmp == 'W')
                robots[i].dir = 0;
            else if(tmp == 'N')
                robots[i].dir = 1;
            else if(tmp == 'E')
                robots[i].dir = 2;
            else if(tmp == 'S')
                robots[i].dir = 3;
        }
        for(int i = 0; i < M; i++){
            scanf("%d", &num);
            getchar();
            scanf("%c", &tmp);
            scanf("%d", &step);
            if(flag == false)
                continue;
            if(tmp == 'F'){
                if(robots[num].dir == 0){
                    for(int j = 1; j <= step && robots[num].x-j > 0; j++){
                        if(arr[robots[num].x - j][robots[num].y] != 0){
                            printf("Robot %d crashes into robot %d\n", num, arr[robots[num].x-j][robots[num].y]);
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false)
                        continue;
                    if(robots[num].x-step > 0){
                        arr[robots[num].x][robots[num].y] = 0;
                        robots[num].x -= step;
                        arr[robots[num].x][robots[num].y] = num;
                    }else{
                        printf("Robot %d crashes into the wall\n", num);
                        flag = false;
                    }
                }else if(robots[num].dir == 1){
                    for(int j = 1; j <= step && robots[num].y+j <= B; j++){
                        if(arr[robots[num].x][robots[num].y+j] != 0){
                            printf("Robot %d crashes into robot %d\n", num, arr[robots[num].x][robots[num].y+j]);
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false)
                        continue;
                    if(robots[num].y+step <= B){
                        arr[robots[num].x][robots[num].y] = 0;
                        robots[num].y += step;
                        arr[robots[num].x][robots[num].y] = num;
                    }else{
                        printf("Robot %d crashes into the wall\n", num);
                        flag = false;
                    }
                }else if(robots[num].dir == 2){
                    for(int j = 1; j <= step && robots[num].x+j <= A; j++){
                        if(arr[robots[num].x + j][robots[num].y] != 0){
                            printf("Robot %d crashes into robot %d\n", num, arr[robots[num].x+j][robots[num].y]);
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false)
                        continue;
                    if(robots[num].x+step <= A){
                        arr[robots[num].x][robots[num].y] = 0;
                        robots[num].x += step;
                        arr[robots[num].x][robots[num].y] = num;
                    }else{
                        printf("Robot %d crashes into the wall\n", num);
                        flag = false;
                    }
                }else if(robots[num].dir == 3){
                    for(int j = 1; j <= step && robots[num].y-j > 0; j++){
                        if(arr[robots[num].x][robots[num].y-j] != 0){
                            printf("Robot %d crashes into robot %d\n", num, arr[robots[num].x][robots[num].y-j]);
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false)
                        continue;
                    if(robots[num].y-step > 0){
                        arr[robots[num].x][robots[num].y] = 0;
                        robots[num].y -= step;
                        arr[robots[num].x][robots[num].y] = num;
                    }else{
                        printf("Robot %d crashes into the wall\n", num);
                        flag = false;
                    }
                }
            }else if(tmp == 'L'){
                robots[num].dir = (robots[num].dir - (step%4) + 4) % 4;
            }else if(tmp == 'R'){
                robots[num].dir = (robots[num].dir + (step%4) + 4) % 4;
            }
        }
        if(flag == true)
            printf("OK\n");
    }

    return 0;
}
