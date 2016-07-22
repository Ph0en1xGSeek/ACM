#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;
int arr[65][65];

int main()
{
    int r, c;
    int x, y, direc = 0;
    char ch;
    memset(arr, 0, sizeof(arr));//0123 иосробвС
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            ch = getchar();
            if(ch == '\n')
                ch = getchar();
            if(ch == ' ')
                arr[i][j] = 1;
        }
    }
    cin >> x >> y;
    while(1)
    {
        ch = getchar();
        if(ch == 'Q')
            break;
        if(ch == 'R')
            direc = (direc + 1)%4;
        else if(ch == 'L')
            direc = (direc - 1)%4;
        else if(ch == 'F')
        {
            if(direc == 0 && arr[x-1][y])
                x--;
            else if(direc == 1 && arr[x][y+1])
                y++;
            else if(direc == 2 && arr[x+1][y])
                x++;
            else if(direc == 3 && arr[x][y-1])
                y--;

        }
    }
    if(direc == 0)
        ch = 'N';
    else if(direc == 1)
        ch = 'E';
    else if(direc == 2)
        ch = 'S';
    else if(direc == 3)
        ch = 'W';
    printf("%d %d %c\n", x, y, ch);

    return 0;
}
