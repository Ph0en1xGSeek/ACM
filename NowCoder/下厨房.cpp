#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    set<string> material_set;
    string material;
    while(cin >> material){
        material_set.insert(material);
    }
    printf("%d\n", material_set.size());
    return 0;
}
