#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int> (c));
    // vector<pair<int,int>> st;
    vector<pair<int,int>> s1; // x,y
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                grid[i][j] = 0;
                s1.push_back({i,j});
            }
        }
    }
    int start = s1.size();
    vector<pair<int,int>> s2;
    int ans = 0;
    int i = 0;
    while (s1.size() != 0) {
        // vector<int> curr = q.front(); q.pop();
        pair<int,int> curr = s1[i++];
        int x = curr.first;
        int y = curr.second;
        grid[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            if (new_x>=0&&new_y>=0&&new_x<r&&new_y<c) {
                if (grid[new_x][new_y] == 0) { // เดินไปได้
                    s2.push_back({new_x,new_y});
                }
            }
        }
        map<pair<int,int>, int> m;
        for (auto & vec : s2) {
            if (m[vec] == 0) m[vec]++;
            m[vec]++;
            if (m[vec] == start) ans++;
            grid[vec.first][vec.second] = 1;
        }
        for (auto & tmp : m) {
            cout << tmp.first.first << " " << tmp.first.second << " " << tmp.second << " ";
        }
        swap(s1,s2);
        s2.clear();
        i = 0;
    }
    cout << ans;
    cout << endl;
}