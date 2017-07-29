// File Name:    main.txt
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #2
// Description:  Read from infile.txt. Put every five string together and change
//				 the even chars to '~' by value. Change the odd chars to '!'.
//               Print to outfile1.txt and outfile2.txt.




#include <iostream>
#include "pgsstring.h"
#include <fstream>

using namespace std;
void evenFunction(ostream & ostr, PGSString str );
void oddFunction( PGSString& str );

int main()
{
    ifstream fin("infile.txt");
    ofstream fout("outfile1.txt");
    ofstream output("outfile2.txt");

    PGSString combinationString;
    PGSString str;
    PGSString emptyStr;
    int counts = 0;

    while(fin >> str)
    {
        combinationString = combinationString + str;
        counts++;
        if(counts == 5)
        {
            counts = 0;
            evenFunction(fout, combinationString );
            oddFunction( combinationString );
            output << combinationString << ' ' << combinationString.length()
                    << ':' << combinationString.capacity() << endl;
            combinationString = emptyStr;
        }
    }


    fin.close();
    fout.close();
    output.close();

    return 0;
}

void evenFunction(ostream & ostr, PGSString str )
{
    for(int i = 0; i < str.length(); i++)
    {
        if(i % 2 == 0)
            str[i] = '~';
    }
    ostr << str << ' ' << str.length() << ':' << str.capacity() << endl;
}

void oddFunction( PGSString& str )
{
    for(int i = 0; i < str.length(); i++)
    {
        if(i % 2 != 0)
            str[i] = '!';
    }
}
