#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool dfs(int a, vector<vector<int>> &adj, vector<int> &visited, int parent, int &res, bool flag) {
    visited[a] = 1;
    if (adj[a].size() > 2) return false; // case more than 2 degree
    if (res < 0) return false; // there can be only 2 one degree
    if (adj[a].size() == 1) res--; 
    for (auto & b : adj[a]) {
        if (visited[b] == 1 && b!=parent) return false; // case loop
        if (visited[b] == 0) {
            if (!dfs(b, adj, visited, a, res, true)) return false;
        }
    }
    return true;
}

int main() {
    int v, e;
    cin >> v >> e;
    if (e == 0) { // case all dot
        cout << v;
        return 0;
    }
    vector<vector<int>> adj(v);
    for (int i = 0 ; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(v, 0);
    int cnt = 0;
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            int res = 2;
            bool flag = false;
            if (dfs(i, adj, visited, -1, res, flag)) {
                if (res == 0) { 
                    cnt++;
                } else if (res == 2 && !flag) { 
                    cnt++;
                }
            } 
        }
    }
    cout << cnt;
}
