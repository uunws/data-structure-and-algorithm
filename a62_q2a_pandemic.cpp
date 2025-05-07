#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, T;
int v[505][505];
queue<vector<int>> q;
vector<int> sx = {-1,1,0,0};
vector<int> sy = {0,0,-1,1};
int vst[505][505];

int main() {
    cin >> r >> c >> T;
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                q.push({i, j, 0});
                cnt++;
            }
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u[0];
        int y = u[1];
        int w = u[2];
        if (w == T) {
            cout << cnt << endl;
            // for (auto &x :vst) {
            //     for (auto &y : x) {
            //         cout << y << " ";
            //     }
            //     cout << endl;
            // }
            return 0;
        }
        vst[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + sx[i];
            int ny = y + sy[i];
            if (nx>=0 && ny>=0 && nx<r && ny<c) { // in range
                if (v[nx][ny] == 0) { // not 1,2
                    if (vst[nx][ny] == 0) {
                        vst[nx][ny] = 1;
                        cnt++;
                        q.push({nx, ny, w+1});
                    }
                }
            }
        }
    }

}