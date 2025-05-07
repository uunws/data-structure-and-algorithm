#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs_cc(int i, map<int, vector<int>> &adj, vector<int> &visited) {
    visited[i] = 1;
    for (auto & j : adj[i]) {
        if (visited[j] == 0) {
            dfs_cc(j, adj, visited);
        }
    }
}

int cc(map<int, vector<int>> &adj, int v_size) {
    vector<int> visited(v_size+1, 0);
    int cnt = 0;
    for (int i = 1; i <= v_size; i++) { // all nodes
        if (visited[i] == 0) {
            cnt++;
            // cout << i << " " << cnt << endl;
            dfs_cc(i, adj, visited);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v,e;
    cin >> v >> e;
    map<int, vector<int>> adj;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << cc(adj, v);
}