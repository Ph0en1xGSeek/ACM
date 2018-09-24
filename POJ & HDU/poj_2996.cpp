#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;


int main(){
    vector<string> white[6];
    vector<string> black[6];
    char tmp[100];
    char board[8][8];
    memset(board, 0, sizeof(board));
    for(int i = 7; i >= 0; i--){
        scanf("%s", tmp);
        scanf("%s", tmp);
        for(int j = 0; j < 8; j++){
            board[i][j] = tmp[2+j*4];
        }
    }
    scanf("%s", tmp);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 'K'){
                string pushStr = "Ka1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                white[0].push_back(pushStr);
            }else if(board[i][j] == 'Q'){
                string pushStr = "Qa1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                white[1].push_back(pushStr);
            }else if(board[i][j] == 'R'){
                string pushStr = "Ra1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                white[2].push_back(pushStr);
            }else if(board[i][j] == 'B'){
                string pushStr = "Ba1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                white[3].push_back(pushStr);
            }else if(board[i][j] == 'N'){
                string pushStr = "Na1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                white[4].push_back(pushStr);
            }else if(board[i][j] == 'P'){
                string pushStr = "a1";
                pushStr[0] = 'a' + j;
                pushStr[1] = '1' + i;
                white[5].push_back(pushStr);
            }
        }
    }
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 'k'){
                string pushStr = "Ka1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                black[0].push_back(pushStr);
            }else if(board[i][j] == 'q'){
                string pushStr = "Qa1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                black[1].push_back(pushStr);
            }else if(board[i][j] == 'r'){
                string pushStr = "Ra1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                black[2].push_back(pushStr);
            }else if(board[i][j] == 'b'){
                string pushStr = "Ba1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                black[3].push_back(pushStr);
            }else if(board[i][j] == 'n'){
                string pushStr = "Na1";
                pushStr[1] = 'a' + j;
                pushStr[2] = '1' + i;
                black[4].push_back(pushStr);
            }else if(board[i][j] == 'p'){
                string pushStr = "a1";
                pushStr[0] = 'a' + j;
                pushStr[1] = '1' + i;
                black[5].push_back(pushStr);
            }
        }
    }
    bool flag = false;
    printf("White:");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < white[i].size(); j++){
            if(flag == false){
                printf(" ");
                flag = true;
            }
            else
                printf(",");
            cout << white[i][j];
        }
    }
    flag = false;
    printf("\nBlack:");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < black[i].size(); j++){
            if(flag == false){
                printf(" ");
                flag = true;
            }
            else
                printf(",");
            cout << black[i][j];
        }
    }
    printf("\n");
    return 0;
}
