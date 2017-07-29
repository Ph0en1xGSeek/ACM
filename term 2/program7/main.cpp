// File Name:    prog7.cpp
// Author:       Pan Guosheng
// Student Number: 3014218157
// Assignment:   #7
// Description:  This program use some algorithm of STL. First we will read from
//				 infile by using transform algorithm to remove ? ! ^ and so on. Then
//               it will be sorted by using AscDictSort, which overlooks upper and
//               lower case. This program also use copy and erase functions


#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

string punctRemover(const string& strIn);

class AscDictSort
{
   public:
    bool operator( ) (const string& str1, const string& str2)
    {
        int len = (str1.length() > str2.length())? str1.length():str2.length();
        for(int i = 0; i < len; i++)
        {
            if(str1[i] % 32 < str2[i] % 32)
                return true;
            else if(str1[i] % 32 > str2[i] % 32)
                return false;
        }
        return false;
    }
};


int main()
{
    set<string>::iterator p;
    set<string, AscDictSort> set1, set2, modSet1, modSet2;
    ifstream fin;
    fin.open("file1.txt");
    transform(istream_iterator<string>(fin), istream_iterator<string>(),
              inserter(set1, set1.begin()), punctRemover);
    fin.close();
    fin.clear();
    fin.open("file2.txt");
    transform(istream_iterator<string>(fin), istream_iterator<string>(),
              inserter(set2, set2.begin()), punctRemover);
    fin.close();
    fin.clear();
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "modSet1's size: " << modSet1.size() << endl;
    cout << "modSet2's size: " << modSet2.size() << endl;
    modSet1 = set1;
    modSet2 = set2;
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "modSet1's size: " << modSet1.size() << endl;
    cout << "modSet2's size: " << modSet2.size() << endl;
    for(p = set2.begin(); p != set2.end(); p++)
    {
            modSet1.erase(*p);
    }
    for(p = set1.begin(); p != set1.end(); p++)
    {
            modSet2.erase(*p);
    }
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "modSet1's size: " << modSet1.size() << endl;
    cout << "modSet2's size: " << modSet2.size() << endl;

    ofstream fout("outfile1.txt");
    copy(modSet1.begin(), modSet1.end(), ostream_iterator<string>(fout, " "));
    fout.close();
    fout.clear();
    fout.open("outfile2.txt");
    copy(modSet2.begin(), modSet2.end(), ostream_iterator<string>(fout, " "));
    fout.close();
    fout.clear();

    return 0;
}

string punctRemover(const string& strIn)
{
    string str;
    for(int i = 0; i < strIn.length(); i++)
    {
        if(isalpha(strIn[i]))
            str += strIn[i];
    }
    return str;
}
