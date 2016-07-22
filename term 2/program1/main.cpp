// File Name:    program1.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #1
// Description:  This program will first open three files, one for input and another two
//				 for output. Then create a PGSString value, and read it till end of file.
//               Every time pass it by value and output to outfile1, pass it by reference
//               and output to outfile2. set it equal to an empty PGSString.


#include <iostream>
#include "pgsstring.h"
#include <fstream>

using namespace std;

void byValue(ostream& ostr, PGSString str );
void byReference( PGSString& str );

int main()
{
    ifstream fin("infile.txt");
    ofstream fout("outfile1.txt");
    ofstream output("outfile2.txt");
    PGSString pgsString;

    while(pgsString.read(fin))
    {
        byValue(fout , pgsString);
        byReference(pgsString);
        pgsString.write(output);
        output << ' ' << pgsString.length() << ':' << pgsString.capacity() << endl;
        pgsString.setEqualTo(PGSString());
    }

    fin.close();
    fout.close();
    output.close();

    return 0;
}

void byReference( PGSString& str )
{
    str.addCharAt('+' , 6);
}

void byValue(ostream& ostr, PGSString str )
{
    str.addCharAt('~' , 2);
    str.write(ostr);
    ostr << ' ' << str.length() << ':' << str.capacity() << endl;
}
