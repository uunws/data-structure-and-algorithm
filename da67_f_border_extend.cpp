#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r,c,k;
vector<vector<int>> grid;
queue<vector<int>> q; // h,i,j
vector<vector<int>> visited;
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int main() {
    cin >> r >> c >> k;
    grid.assign(r, vector<int> (c));
    visited.assign(r, vector<int> (c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x; // 0-base
            grid[i][j] = x;
            if (x == 1) {
                q.push({0, i, j});
                visited[i][j] = 1;
            }
        }
    }
    vector<vector<int>> ans = grid; // copy grid
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int h = u[0];
        int x = u[1];
        int y = u[2];
        // ไปได้ 4 อัน บน ล่าง ซ้าย ขวา
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x>=0&&new_y>=0&&new_x<r&&new_y<c) {
                if (visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    if (h < k && ans[new_x][new_y] == 0) {
                        ans[new_x][new_y] = 2;
                        q.push({h+1,new_x,new_y});
                    }
                }
            }
        }
    }
    for (auto & x : ans) {
        for (auto & y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}