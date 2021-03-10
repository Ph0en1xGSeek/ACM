#include <iostream>
#include <vector>
#include <string.h>
 
using namespace std;
 
int arr[9][9] = {0};
bool row[9][9] = {false};
bool col[9][9] = {false};
bool grid[3][3][9] = {false};
 
bool dfs(vector<pair<int, int>> &zeros, int pos, int size) {
    if(pos == size) {
        return true;
    }
    int x = zeros[pos].first;
    int y = zeros[pos].second;
    for(int i = 0; i < 9; ++i) {
        if(row[x][i] == false && col[y][i] == false && grid[x / 3][y / 3][i] == false) {
            arr[x][y] = i+1;
            row[x][i] = col[y][i] = grid[x / 3][y / 3][i] = true;
            if(dfs(zeros, pos + 1, size)) {
                return true;
            }
            row[x][i] = col[y][i] = grid[x / 3][y / 3][i] = false;
            arr[x][y] = 0;
        }
    }
    return false;
}
 
int main() {
    vector<pair<int, int>> zeros;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) {
                row[i][arr[i][j] - 1] = true;
                col[j][arr[i][j] - 1] = true;
                grid[i / 3][j / 3][arr[i][j] - 1] = true;
            }else {
                zeros.push_back({i, j});
            }
        }
    }
    int size = zeros.size();
    dfs(zeros, 0, size);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}