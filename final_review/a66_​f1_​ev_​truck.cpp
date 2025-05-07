#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(n,-1));
    for (int i = 0; i < m; i++) {
        int a,b,e;
        cin >> a >> b >> e;
        g[a][b] = e;
        g[b][a] = e;
    }
    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            if (g[i][j] == -1) continue;
            dist[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]  +dist[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) continue;
            if (dist[i][j] > ans) ans = dist[i][j];
        }
    }
    cout << ans;
}