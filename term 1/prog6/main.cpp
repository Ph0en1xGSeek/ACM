//
// Author:       Panguosheng
// Student Number: 3014218157
// Assignment:   #6
// Description:  This program will open a file that containing a list of some names and
//  the hours they work each day. Then sort them in order and print to the
//  screen.



#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;
void readTheFile(string name[] , int hour[][7] , int &numberOfEp);
void toTal(int total[] , int hour[][7] , int numberOfEp);
void bubbleSort(int total[] , int hour[][7] , string name[] , int numberOfEp);
bool isInSort(int seq[] , int numberOfEp);
void write(string date[] , string name[] , int hour[][7] , int total[] , int numberOfEp);

int main()
{
    string name[50];
    int hour[50][7];
    int total[50] = {0};
    int numberOfEp;
    string date[] = {"S" , "M" , "T" , "W" , "Th" , "F" , "Sa" };

    readTheFile(name , hour , numberOfEp);
    toTal(total , hour , numberOfEp);
    bubbleSort(total , hour , name , numberOfEp);
    write(date , name , hour , total , numberOfEp);


    return 0;
}



void readTheFile(string name[] , int hour[][7] , int &numberOfEp)
{

    ifstream input("empdata4.txt");
    if(input.fail())
    {
        exit(1);
    }
    input >> numberOfEp;

    for(int i = 0 ; i < numberOfEp ; i++)
    {
        input >> name[i];
        for(int j = 0 ; j < 7 ; j++)
        {
               input >> hour[i][j];
        }
    }
    input.close();
}


void toTal(int total[] , int hour[][7] , int numberOfEp)
{
    for(int i = 0 ; i < numberOfEp ; i++)
    {
        for(int j = 0 ; j < 7 ; j++)
            total[i] += hour[i][j];
    }
}


void bubbleSort(int total[] , int hour[][7] , string name[] , int numberOfEp)
{
    while(!isInSort(total , numberOfEp))
    {
        for(int i = 0 ; i < numberOfEp - 1 ; i++)
            if(total[i] > total[i + 1])
            {
                swap(total[i] , total[i + 1]);
                for(int j = 0 ; j < 7 ; j++)
                {
                    swap(hour[i][j] , hour[i +1][j]);
                }
                swap(name[i] , name[i + 1]);
            }
    }

}


bool isInSort(int seq[] , int numberOfEp)
{
    for(int i = 0 ; i < numberOfEp - 1 ; i++)
    {
        if (seq[i] > seq[i + 1])
            return false;
    }
    return true;
}


void write(string date[] , string name[] , int hour[][7] , int total[] , int numberOfEp)
{
    cout << left << setw(20) << "Nr" << " "  ;
    for(int j = 0 ; j < 7 ; j++)
        cout << left << setw(3) << date[j] << " ";
    cout << "TL" << endl;
    for(int i = numberOfEp -1 ; i >= 0 ; i--)
    {
        cout << left << setw(20) << name[i] << " " ;
        for(int j = 0 ; j < 7 ; j++)
            cout << left << setw(2) << hour[i][j] << "  ";
        cout << total[i] << endl;
    }
}



/*
Nr                   S   M   T   W   Th  F   Sa  TL
Kirk,James           10  10  0   10  12  0   0   42
Rugg,James           7   3   8   7   2   5   7   39
Bosco,Sam            7   3   8   7   2   5   7   39
Peters,Greg          5   6   5   6   5   6   5   38
VanPelt,Grace        5   6   5   6   5   6   5   38
Jane,Patrick         9   3   7   5   8   0   0   32
Theiss,Bill          9   10  4   7   0   0   0   30
Lilly,Jack           2   3   8   3   6   3   5   30
Rigsby,Wayne         9   10  4   7   0   0   0   30
Lisbon,Teresa        2   3   8   3   6   3   5   30
Daniels,Carl         8   8   3   0   8   2   0   29
Cho,Kimball          8   8   3   0   8   2   0   29
Minelli,Virgil       2   5   3   0   4   9   4   27
McCoy,Lenard         0   4   0   8   4   0   2   18
Scott,Annis          1   6   2   0   0   1   0   10

Process returned 0 (0x0)   execution time : 0.219 s
Press any key to continue.





Nr                   S   M   T   W   Th  F   Sa  TL
Kirk,James           10  10  0   10  12  0   0   42
Uhura,Nyota          10  10  0   8   12  0   0   40
Leslie,Eddie         5   6   5   6   7   6   5   40
Ryan,Kevin           5   6   7   6   5   6   5   40
Chekov,Pavel         7   3   8   7   2   5   7   39
Rugg,James           7   3   8   7   2   5   7   39
Bosco,Sam            7   3   8   7   2   5   7   39
Parish,Lanie         7   3   8   6   2   5   7   38
Peters,Greg          5   6   5   6   5   6   5   38
VanPelt,Grace        5   6   5   6   5   6   5   38
Esposito,Javier      2   5   3   9   4   9   4   36
Beckett,Kate         2   8   8   3   6   3   5   35
Galloway,David       9   10  4   8   0   0   2   33
Sulu,Hikaru          2   3   8   5   6   3   5   32
Castle,Richard       4   3   7   5   8   0   5   32
Jane,Patrick         9   3   7   5   8   0   0   32
Montgo,Roy           9   2   4   7   0   0   8   30
Theiss,Bill          9   10  4   7   0   0   0   30
Lilly,Jack           2   3   8   3   6   3   5   30
Rigsby,Wayne         9   10  4   7   0   0   0   30
Lisbon,Teresa        2   3   8   3   6   3   5   30
Daniels,Carl         8   8   3   0   8   2   0   29
Cho,Kimball          8   8   3   0   8   2   0   29
Rodgers,Martha       8   7   3   0   8   2   0   28
Chapel,Christine     1   6   2   8   9   1   0   27
Minelli,Virgil       2   5   3   0   4   9   4   27
Kyle,John            8   8   3   0   2   2   0   23
McCoy,Lenard         0   4   0   8   4   0   2   18
Rand,Janice          0   4   0   8   3   0   2   17
Scott,Annis          1   6   2   0   0   1   0   10

Process returned 0 (0x0)   execution time : 0.281 s
Press any key to continue.

*/
