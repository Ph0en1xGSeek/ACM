#include <iostream> 
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<vector<int>> arr(num+1, vector<int>(num+1));
    vector<vector<int>> row(num+1, vector<int>(num+1, 0));
    vector<vector<int>> col(num+1, vector<int>(num+1, 0));
    for(int i = 1; i <= num; ++i) {
        for(int j = 1; j <= num; ++j) {
            cin >> arr[i][j];
            row[i][j] = row[i][j-1] + arr[i][j];
            col[i][j] = col[i-1][j] + arr[i][j];
        }
    }
    int mx = 0;
    for(int i = 1; i <= num; ++i) {
        for(int j = 1; j <= num; ++j) {
            for(int l = mx + 1; i + l - 1 <= num && j + l - 1 <= num; ++l) {
                if(row[i][j+l-1] - row[i][j-1] < l) {
                    break;
                }
                if(col[i+l-1][j] - col[i-1][j] < l) {
                    break;
                }
                if(row[i+l-1][j+l-1] - row[i+l-1][j-1] < l) {
                    continue;
                }
                if(col[i+l-1][j+l-1] - col[i-1][j+l-1] < l) {
                    continue;
                }
                mx = l;
            }
        }
    }
    cout << mx << endl;
    return 0;
}