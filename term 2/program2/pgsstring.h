// File Name:    pgsstring.h
// Author:       Pan Guosheng
// Student Number: 3014218157

// Assignment:   #2
// Class Description:  This is a class contain only cstring that is similar to the string class of C++.
//				     We can get the length and capacity of the string. we can also append a string by using
//                  operator '+' '='. It can read from and write to both file and screen(keyboard).

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
        int capacity() const;        //return the capacity the string can use
        void addCharAt(char ch, int i );  //add a char at
        PGSString& operator=(const PGSString& str);
        char& operator[](const int index) const;
        friend PGSString operator+(const PGSString& lstr , const PGSString& rstr);
        friend istream& operator>>(istream& istr , PGSString& str);
        friend ostream& operator<<(ostream& ostr , PGSString& str);

    protected:

    private:
        int size;
        int end;
        char* str;
};

#endif // PGSSTRING_H
