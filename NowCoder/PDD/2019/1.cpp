#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INTMAX = 0x7fffffff;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(10);
    string num;
    cin >> num;
    for(int i = 0; i < n; ++i) {
        arr[num[i] - '0'].push_back(i);
    }
    int ans = INTMAX;
    vector<int> fin_num;
    for(int i = 0; i < 10; ++i) {
        int cur_k = arr[i].size();
        int exp = 0;
        for(int j = 1; j < 10; ++j) {
            int inc = 0;
            if(i + j < 10) {
                inc += arr[i + j].size();
            }
            if(i - j >= 0) {
                inc += arr[i - j].size();
            }
            if(cur_k + inc < k) {
                cur_k += inc;
                exp += j * inc;
            }else {
                exp += j * max(0, (k - cur_k));
                break;
            }
        }
        if(exp < ans) {
            ans = exp;
            fin_num.clear();
            fin_num.push_back(i);
        }else if(exp == ans) {
            fin_num.push_back(i);
        }
    }
    vector<string> str_ans;
    for(int fin : fin_num) {
        string tmp = num;
        int cur_k = arr[fin].size();
        for(int j = 1; j < 10; ++j) {
            int inc = 0;
            if(fin + j < 10) {
                inc += arr[fin + j].size();
            }
            if(fin - j >= 0) {
                inc += arr[fin - j].size();
            }
            if(cur_k + inc < k) {
                cur_k += inc;
                if(fin - j >= 0) {
                    for(int i = 0; i < arr[fin - j].size(); ++i) {
                        tmp[arr[fin-j][i]] = fin + '0';
                    }
                }
                if(fin + j < 10) {
                    for(int i = 0; i < arr[fin + j].size(); ++i) {
                        tmp[arr[fin+j][i]] = fin + '0';
                    }
                }
            }else {
                if(fin + j < 10) {
                    for(int i = 0; i < arr[fin + j].size() && cur_k < k; ++i) {
                        tmp[arr[fin+j][i]] = fin + '0';
                        ++cur_k;
                    }
                }
                if(fin - j >= 0) {
                    for(int i = arr[fin - j].size() - 1; i >= 0 && cur_k < k; --i) {
                        tmp[arr[fin-j][i]] = fin + '0';
                        ++cur_k;
                    }
                }
                break;
            }
        }
        str_ans.push_back(tmp);
    }
    sort(str_ans.begin(), str_ans.end());
    cout << ans << endl;
    cout << str_ans[0] << endl;

    return 0;
}