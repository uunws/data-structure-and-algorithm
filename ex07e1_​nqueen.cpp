#include <iostream>
#include <vector>
using namespace std;

int n;

// n*n board , n queen
// 1 แถว มีได้ 1 queen
// 0-base

int cnt;

void flood(vector<vector<int>> &grid, int step, int x) { // step : column, x : select row
    for (int j = 0; j < n; j++) { // row
        for (int k = step+1; k < n; k++) { // column
            int abs1 = abs(j-x);
            int abs2 = abs(step-k);
            if (abs1 == abs2) {
                grid[j][k] = 1;
            }
        }
    }
}

void recur(int step, vector<int> &col, vector<bool> &used, vector<vector<int>> &grid) {
    if (step < n) {
        for (int i = 0; i < n; i++) {
            if (grid[i][step]) continue;
            if (!used[i]) {
                used[i] = true;
                col[step] = i;
                auto grid_tmp = grid; // copy
                flood(grid, step, i);
                recur(step+1, col, used, grid);
                used[i] = false; // backtrack
                swap(grid,grid_tmp); // swap back (backtrack)
            }
        }
    } else {
        cnt++;
    }
}

int main() {
    cin >> n;
    vector<int> col(n);
    vector<bool> used(n);
    vector<vector<int>> grid(n, vector<int> (n, 0));
    cnt = 0;
    recur(0,col,used,grid);
    cout << cnt;
}