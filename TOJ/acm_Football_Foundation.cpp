#include <iostream>

using namespace std;

int main()
{
    struct Grd
    {
        char derection;
        int step;
    };

    int row , col , start;
    cin >> row >> col >> start;


    while(row != 0 && col != 0 && start != 0)
    {
        Grd grid[10][10];
        for(int i = 0 ; i < 10 ; i++)
        {
            for(int j = 0 ; j < 10 ; j++)
            {
                grid[i][j].step = 0;
            }

        }
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                cin >> grid[i][j].derection;
            }

        }


        int x = 0 , y = start - 1, counts = 0;
    //cout << grid[x][y].derection << endl;
        while(x >= 0 && y >= 0 && x < row && y < col)
        {
            if(grid[x][y].derection == 'N')
            {
                x -= 1;
                counts++;
            }
            else if(grid[x][y].derection == 'W')
            {
                y -= 1;
                counts++;
            }
            else if(grid[x][y].derection == 'S')
            {
                x += 1;
                counts++;
            }
            else if(grid[x][y].derection == 'E')
            {
                y += 1;
                counts++;
            }

            if(grid[x][y].step != 0)
            {
            //cout << x << "  " << y << endl;
                cout << grid[x][y].step << " step(s) before a loop of " << counts - grid[x][y].step << " step(s)" <<endl;
                break;
            }
            else if(x >= 0 && y >= 0 && x < row && y < col)
                grid[x][y].step = counts;

        }
        if(grid[x][y].step == 0)
            cout << counts << " step(s) to exit" << endl;
        cin >> row >> col >> start;
    }

    return 0;
}
