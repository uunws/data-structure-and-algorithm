#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int r,c;
vector<vector<int>> v;
int visited[1002][1002];
queue<vector<int>> q;
vector<int> sx = {-1,1,0,0}; // up down
vector<int> sy = {0,0,-1,1}; // left right

int main() {
    cin >> r >> c;
    v.assign(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            string res = s.substr(j, 1);
            if (res == ".") {
                v[i][j] = 0;
            } else if (res == "#") {
                v[i][j] = 1;
            }
        }
    }
    // bfs
    // always get shortest path?
    q.push({{0,0,0}}); // push {x,y,w}
    visited[0][0] = 1;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u[0];
        int y = u[1];
        int w = u[2];
        if (x == r-1 && y == c-1) {
            cout << w;
            return 0;
        }
        for (int i = 0; i < 4; i++) { // 4 : up down left right
            int new_x = x + sx[i]; 
            int new_y = y + sy[i];
            if (new_x>=0&&new_y>=0&&new_x<r&&new_y<c) { // check is it in range
                if (v[new_x][new_y]) continue; // check is it forbidden to enter
                if (visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    q.push({new_x, new_y, w+1}); // push
                }
            }
        }
    }
    cout << "-1";
}