#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int r,c,T;
    vector<vector<int>> grid(r, vector<int> c);
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i,j,0});
                cnt++;
            }
        }
    }
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u[0];
        int y = u[1];
        int w = u[2];
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_y < 0 || new_x >= r || new_y >= c) continue;
            if (grid[new_x][new_y] == 0) {
                grid[new_x][new_y] = 1;
                cnt++;
                q.push({new_x, new_y, w+1});
            }
        }
        cout << cnt;
    }

}