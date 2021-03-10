#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2) {
        vector<int> num1(str1.size(), 0);
        vector<int> num2(str2.size(), 0);
        vector<int> product(str1.size()+1, 0);
        vector<int> ans(str1.size() + str2.size(), 0);
        for(int i = str1.size()-1, j = 0; i >= 0; --i) {
            num1[j++] = (str1[i] - '0');
        }
        for(int i = str2.size()-1, j = 0; i >= 0; --i) {
            num2[j++] = (str2[i] - '0');
        }
        for(int i = 0; i < num2.size(); ++i) {
            int jin = 0, tmp;
            for(int j = 0; j < num1.size(); ++j) {
                tmp = num1[j] * num2[i] + jin;
                product[j] = tmp % 10;
                jin = tmp / 10;
            }
            product[num1.size()] = jin;
            jin = 0;
            for(int j = 0; j < product.size(); ++j) {
                tmp = ans[j + i] + product[j] + jin;
                ans[j + i] = tmp % 10;
                jin = tmp / 10;
            }
            ans[product.size() + i] = jin;
        }
        while(ans[ans.size() - 1] == 0) {
            ans.pop_back();
        }
        for(int i = ans.size() - 1; i >= 0; --i) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
