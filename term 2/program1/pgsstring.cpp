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

char PGSString::at(int index) const
{
    if(index >= 0 && index <= end)
        return *(str + index);
    else
        return '\0';
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

void PGSString::setEqualTo(const PGSString& str)
{
    if(this != &str)
    {
        this->size = str.size;
        this->end = str.end;
        delete [] (this->str);
        this->str = new char [size];
        for(int i = 0; i <= end; i++)
        {
            *(this->str + i) = *(str.str + i);
        }
    }
}

void PGSString::write(ostream& ostr)
{
    ostr << str;
}

bool PGSString::read(istream& istr)
{
    char newStr[100];
    newStr[0] = '\0';
    istr >> newStr;
    int newEnd;
    for(newEnd = 0 ; *(newStr + newEnd) != '\0' ; newEnd++);
    if(newEnd != 0)
    {
        end = newEnd;
        size = 20;
        while(size - 1 < end)
            size += 20;
        delete [] str;
        this->str = new char [size];
        for(int i = 0; i <= end; i++)
        {
            *(str + i) = *(newStr + i);
        }
        return true;
    }
    else
        return false;
}



