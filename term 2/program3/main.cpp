// File Name:    program3.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #3
// Description:  This program will show one solution of the famous question the Knight's
//				 Tour. Solved by recursion.





#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isValid(int x, int y, int n);
void printBoard(int);

int board[8][8] = {{0}};
int counts = 1; //to show how many steps that have walked


int main()
{
    isValid(0, 0, counts);
    printBoard(8);
    return 0;
}

bool isValid(int x, int y, int n)
{
    if(x >= 0 && y >= 0 && x <= 7 && y <= 7 && board[x][y] == 0)
    {

        board[x][y] = n;
        if(n == 64)
            return true;

        n++;
        if(isValid(x + 1, y + 2, n))
            return true;
        else if(isValid(x + 2, y + 1, n))
            return true;
        else if(isValid(x + 1, y - 2, n))
            return true;
        else if(isValid(x - 2, y + 1, n))
            return true;
        else if(isValid(x + 2, y - 1, n))
            return true;
        else if(isValid(x - 2, y - 1, n))
            return true;
        else if(isValid(x - 1, y + 2, n))
            return true;
        else if(isValid(x - 1, y - 2, n))
            return true;
        else
        {
            board[x][y] = 0;
            n--;
            return false;
        }


    }
    else
        return false;

}

void printBoard(int sizeOfBoard)
{
    for(int i = 0; i < sizeOfBoard; i++)
    {
        for(int j = 0; j < sizeOfBoard; j++)
            cout << setw(3) << board[i][j];
        cout << endl;
    }
    cout << endl;
}
