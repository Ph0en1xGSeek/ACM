#include "pgsstring.h"
#include <iostream>
using namespace std;

PGSString::PGSString()
{
    size = 20;
    end = 0;
    str = new char[size];
    str[0] = '\0';
}

PGSString::~PGSString()
{
    delete [] str;
}

PGSString::PGSString(const char* str)
{
    size = 20;
    for(end = 0 ; *(str + end) != '\0' ; end++);
    while(size - 1 < end)
        size += 20;
    this->str = new char[size];
    for(int i = 0 ; i <= end ; i++)
    {
        *(this->str + i) = *(str + i);
    }
}

PGSString::PGSString(const PGSString & str)//copy constructor
{
    this->size = str.size;
    this->end = str.end;
    this->str = new char[size];
    for(int i = 0 ; i <= end ; i++)
       *(this->str + i) = *(str.str + i);
}

int PGSString::length() const
{
    return end;
}

int PGSString::capacity() const
{
    return size;
}

void PGSString::addCharAt(char ch, int i )
{
    if(i >= 0 && i <= end)
    {
        if(end == size - 1)
            size += 20;

        char* newStr = new char [size];

        end++;
        for(int j = 0; j < i - 1 ; j++)
        {
            *(newStr + j) = *(str + j);
        }
        *(newStr + i - 1) = ch;
        for(int j = i; j <= end; j++)
        {
            *(newStr + j) = *(str + j - 1);
        }

        delete [] str;
        str = newStr;
    }

}

PGSString& PGSString::operator=(const PGSString& str1)
{
    if(this != &str1)
    {
        size = str1.size;
        end = str1.end;
        delete [] str;
        str = new char [size];

        for(int i = 0; i <= end; i++)
        {
            *(str + i) = *(str1.str + i);
        }
    }
    return *this;
}

char& PGSString::operator[](const int index) const
{
    if(index <= end && index >= 0)
        return str[index];
    else
        return str[end];
}

PGSString operator+(const PGSString& lstr , const PGSString& rstr)
{
    PGSString nstr;
    nstr.end = lstr.end + rstr.end;
    while(nstr.end + 1 > nstr.size)
        nstr.size += 20;
    delete [] nstr.str;
    nstr.str = new char [nstr.size];
    for(int i = 0 ; i <= lstr.end ; i++)
        nstr.str[i] = lstr.str[i];
    for(int i = lstr.end ; i <= nstr.end ; i++)
        nstr.str[i] = rstr.str[i - lstr.end];
    return nstr;
}

istream& operator>>(istream& istr , PGSString& str)
{
    char* newStr = new char [500];
    newStr[0] = '\0';
    istr >> newStr;
    int newEnd;
    for(newEnd = 0 ; *(newStr + newEnd) != '\0' ; newEnd++);
    if(newEnd != 0)
    {
        str.end = newEnd;
        str.size = 0;
        while(str.size - 1 < str.end)
            str.size += 20;
        delete [] str.str;
        str.str = new char [str.size];
        for(int i = 0; i <= str.end; i++)
        {
            *(str.str + i) = *(newStr + i);
        }
        delete [] newStr;
        return istr;
    }
    else
    {
        delete [] newStr;
        return istr;
    }
}

ostream& operator<<(ostream& ostr , PGSString& str)
{
    ostr << str.str;
    return ostr;
}
