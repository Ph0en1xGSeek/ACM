#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    int size = input.size();
    int space_cnt = 0;
    for(int i = 0; i < size; ++i) {
        if(input[i] == ' ') {
            ++space_cnt;
        }
    }
    int new_size = size + 2 * space_cnt;
    string output(new_size, ' ');
    int pos = new_size - 1;
    for(int i = size-1; i >= 0; --i) {
        if(input[i] == ' ') {
            output[pos--] = '0';
            output[pos--] = '2';
            output[pos--] = '%';
        }else {
            output[pos--] = input[i];
        }
    }
    cout << output << endl;
    return 0;
}