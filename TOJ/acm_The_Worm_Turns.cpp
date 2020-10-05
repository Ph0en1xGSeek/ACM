#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int num , counts = 19;
    char direction;
    cin >> num;
    struct Unit
    {
        int step = 0;
    };

    //Initialize the board
    Unit board[50][50];
    for(int i = 10 ; i < 30 ; ++i)
    {
        board[24][i].step = i - 10;
    }

    //start the game
    int x = 24, y = 29;
    for(int j = 0; j < num ; j++)
    {
        cin >> direction;
        if(direction == 'N')
            x--;
        else if(direction == 'S')
            x++;
        else if(direction == 'W')
            y--;
        else if(direction == 'E')
            y++;

        //cout << x << " " << y <<endl;
        counts++;
        if(x > 49 || y > 49 || x < 0 || y < 0)
        {
            cout << "The worm ran off the board on move " << counts - 19 << endl;
            return 0;
        }
        else if(board[x][y].step != 0 && board[x][y].step > counts - 20)
        {
            cout << "The worm ran into itself on move " << counts - 19 << endl;
            return 0;
        }
        else
            board[x][y].step = counts;
    }
    cout << "The worm successfully made all " << num << " moves" << endl;

    return 0;
}
