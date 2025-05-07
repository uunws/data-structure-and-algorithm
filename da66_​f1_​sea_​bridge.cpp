#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int> (c));
    queue<vector<int>> q; // h,i,j
    vector<vector<int>> visited(r, vector<int> (c, 0));
    for (int i = 0; i < r; i++) { // 0-base
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            grid[i][j] = x;
            if (x == 1) {
                q.push({1,i,j});
                visited[i][j] = 1;
            }
        }
    }
    int ans = 10000;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int h = u[0];
        int x = u[1];
        int y = u[2];
        if (grid[x][y] == 2) {
            ans = min(ans, h);
        }
        if (grid[x][y] == 3) continue;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x>=0 && new_y>=0 && new_x<r && new_y<c) {
                if (visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    q.push({h+1, new_x, new_y});
                }
            }
        }
    }
    // //
    // for (auto & x : visited) {
    //     for (auto & y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << ans;
}