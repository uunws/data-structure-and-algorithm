#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int i, map<int, vector<int>> &adj, vector<int> &visited, int parent) {
    visited[i] = 1;
    if (adj.find(i) != adj.end()) {
        for (auto & b : adj[i]) {
            if (visited[b] == 0) {
                if (dfs(b, adj, visited, i)) return true; 
            } else if (b != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(map<int, vector<int>> &adj, int n) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adj, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        map<int, vector<int>> adj;
        int n, e;
        cin >> n >> e;
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ans = isCycle(adj, n);
        if (ans == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
