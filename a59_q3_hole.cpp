#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,a,b;
vector<vector<int>> hole; // 0:no hole,1:has hole,2:เดินผ่าน
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};
queue<vector<int>> q;

int main() {
    cin >> n >> a >> b;
    hole.assign(1005, vector<int> (1005, 0)); // โจทย์กำหนดว่าขนาด1000ช่อง!!
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        hole[x][y] = 1; 
    }
    q.push({a,b,0}); // start at home
    hole[a][b] = 2;
    int min_h = 50001;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        int x1 = u[0];
        int y1 = u[1];
        int h = u[2];
        for (int k = 0; k < 4; k++) { // เดินได้ 4 ทิศ
            int new_x = x1 + dx[k];
            int new_y = y1 + dy[k];
            if (new_x>0&&new_y>0&&new_x<=1000&&new_y<=1000) {
                if (hole[new_x][new_y] != 2) {
                    int new_h = 0;
                    if (hole[new_x][new_y] == 1) {
                        new_h = h+1;
                        if (h < min_h) q.push({new_x, new_y, new_h});
                    } else {
                        if (h < min_h) q.push({new_x, new_y, h});
                    }
                    hole[new_x][new_y] = 2;
                }
            } else {
                min_h = min(min_h, h);
            }
        }
    }
    cout << min_h;
}