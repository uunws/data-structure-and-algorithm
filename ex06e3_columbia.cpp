#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int r,c;
vector<vector<int>> fee; 
vector<vector<int>> ans;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
vector<vector<int>> visited;
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

int main() {
    cin >> r >> c;
    fee.assign(r+1, vector<int> (c+1, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> fee[i][j];
        }
    }
    // let (0,0) be starting point
    ans.assign(r, vector<int> (c, INT_MAX));
    ans[0][0] = 0; // initialize at edges 0
    pq.push({0,0,0}); // w,x,y
    visited.assign(r, vector<int> (c, 0));
    visited[0][0] = 1;
    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        int w = u[0];
        int x = u[1];
        int y = u[2];
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_y >= 0 && new_x < r && new_y < c) {
                if (visited[new_x][new_y] == 0) {
                    visited[new_x][new_y] = 1;
                    int new_cost = w + fee[new_x][new_y];
                    ans[new_x][new_y] = new_cost;
                    pq.push({new_cost, new_x, new_y});
                }
            }
        }
    }  
    for (auto & x : ans) {
        for (auto & y : x) {
            cout << y << " ";
        }
        cout << endl;
    } 
}