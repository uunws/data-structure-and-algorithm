#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
vector<int> c;
map<int, vector<int>> adj;
queue<int> q;
vector<int> visited; // เก็บค่า min -1 : not visited
vector<int> indeg;

int main() {
    cin >> n >> m;
    c.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    indeg.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    int ans_max = 0;
    for (int i = 0; i < n; i++) { 
        // อย่าเริ่มที่แค่ตัวที่ indeg เปน 0 เพราะอาจมีกรณีที่ ทุกตัวมี indeg หมด 
        // เลยต้องไล่เชคทุกตัวเป็น start node
        // if (indeg[i] == 0) {
            q.push(i);
            visited.assign(n, -1);
            visited[i] = c[i];
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto & b : adj[u]) {
                    if (visited[b] == -1) {
                        if (c[b] > visited[u]) {
                            ans_max = max(ans_max, c[b] - visited[u]);
                        }
                        visited[b] = min(visited[u], c[b]);
                        q.push(b);
                    }
                }
            }
        // }
    }
    // //
    // for (auto & x : visited) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // //
    cout << ans_max;
}