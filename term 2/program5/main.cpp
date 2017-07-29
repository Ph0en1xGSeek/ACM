// File Name:    prog5.cpp

// Class #       Class 1
// Author:     Pan Guosheng
// Student Number: 3014218157
// Assignment:   #5
// Description:  This program uses STL container set. First, we will create 5 sets
//				 of string. Then, read from infile. Call the erase function to remove
//               same words. Output to screen the number of words, and output the
//               words to outfiles.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;


int main()
{
    set<string>  set1,  set2,  set3,  modSet1,  modSet2;
    set<string>::iterator p;
    ifstream fin;
    fin.open("file1.txt");
    copy(istream_iterator<string>(fin), istream_iterator<string>(), inserter(set1, set1.begin()));
    fin.close();
    fin.clear();
    fin.open("file2.txt");
    copy(istream_iterator<string>(fin), istream_iterator<string>(), inserter(set2, set2.begin()));
    fin.close();
    fin.clear();
    fin.open("file3.txt");
    copy(istream_iterator<string>(fin), istream_iterator<string>(), inserter(set3, set3.begin()));
    fin.close();
    fin.clear();
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "Set3's size: " << set3.size() << endl;
    cout << "modSet1's size: " << modSet1.size() << endl;
    cout << "modSet2's size: " << modSet2.size() << endl;
    modSet1 = set1;
    modSet2 = set2;
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "Set3's size: " << set3.size() << endl;
    cout << "modSet1's size: " << modSet1.size() << endl;
    cout << "modSet2's size: " << modSet2.size() << endl;
    for(p = set2.begin(); p != set2.end(); p++)
    {
            modSet1.erase(*p);
    }
    for(p = set3.begin(); p != set3.end(); p++)
    {
            modSet1.erase(*p);
    }
    for(p = set1.begin(); p != set1.end(); p++)
    {
            modSet2.erase(*p);
    }
    for(p = set3.begin(); p != set3.end(); p++)
    {
            modSet2.erase(*p);
    }
    cout << "Set1's size: " << set1.size() << endl;
    cout << "Set2's size: " << set2.size() << endl;
    cout << "Set3's size: " << set3.size() << endl;
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
