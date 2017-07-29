//
// Author:       Pan Guosheng
// Student Num:  3014218157
// Assignment:   #5
// Description:  This program allows you to input a file's name and then counts the
//  number of different length of words



#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    string fileName;
    cout << "Word Counter" << endl;
    do{

        cout << "What file would you like a report on (or type exit to quit): ";


        cin >> fileName;
        if (fileName == "exit")
            return 0;

        ifstream fin(fileName.c_str());

        while (fin == false)//check the file
        {
            cout << "I'm sorry " << fileName << " can not be found." << endl;
            cout << "What file would you like a report on (or type exit to quit): ";
            fin.close( );
            fin.clear( );
            cin >> fileName;
            if (fileName == "exit")
                return 0;
            fin.open(fileName.c_str());
        }

        string len[] = {"1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , ">8"};
        int counts[9] = {0};
        string word;
        int total = 0;

        while (fin >> word) //count the word
        {

            total++;

            switch (word.length())
            {
                case 1: counts[0]++;
                break;
                case 2: counts[1]++;
                break;
                case 3: counts[2]++;
                break;
                case 4: counts[3]++;
                break;
                case 5: counts[4]++;
                break;
                case 6: counts[5]++;
                break;
                case 7: counts[6]++;
                break;
                case 8: counts[7]++;
                break;
                default : counts[8]++;

            }

        }

        cout << "\n\n\n";
        cout << setw(35) << "Hehe.   Word Report of " << fileName << endl;
        cout << setw(20) << "Length" << setw(20) << "Count" << endl;
        for (int i = 0 ; i < 9 ; i++)
        {
            cout << setw(18) << len[i] << setw(20) << counts[i] << endl;
        }
        cout << "Total words in the file: " << total << endl << endl;

        fin.close();
        fin.clear();

    }
    while (fileName != "exit");
    return 0;
}


/*
Word Counter
What file would you like a report on (or type exit to quit): badname
I'm sorry badname can not be found.
What file would you like a report on (or type exit to quit): infile.txt



            Hehe.   Word Report of infile.txt
              Length               Count
                 1                  42
                 2                  91
                 3                 103
                 4                 115
                 5                  57
                 6                  47
                 7                  25
                 8                  27
                >8                  17
Total words in the file: 524

What file would you like a report on (or type exit to quit): exit

Process returned 0 (0x0)   execution time : 52.141 s
Press any key to continue.
*/
