// File Name:    pgsstring.h
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #1
// Class Description:  This is a class contain only cstring that is similar to the string class of C++.
//				  We can get the length and capacity of the string. we can also index it like string and
//           add a char at wherever you want. It can read from and write to both file and screen(keyboard).

#ifndef PGSSTRING_H
#define PGSSTRING_H
#include <iostream>
using namespace std;


class PGSString
{
    public:
        PGSString();
        virtual ~PGSString();
        PGSString(const char* str);
        PGSString(const PGSString & str);
        int length() const;       //return the length of the string
        char at(int index) const;     //index
        int capacity() const;        //return the capacity the string can use
        void addCharAt(char ch, int i );  //add a char at
        void setEqualTo(const PGSString& str);  //set strA equal to strB
        void write(ostream& ostr);  //write to the screen or the file
        bool read(istream& istr);   //read from keyboard or file

    protected:

    private:
        int size;
        int end;
        char* str;
};

#endif // PGSSTRING_H
