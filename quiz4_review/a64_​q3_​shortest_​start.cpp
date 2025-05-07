#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int v;
    cin >> v;
    vector<int> dist(n,INT_MAX);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dist[x] = 0;
    }
    vector<vector<int>> g(n,vector<int>(3));
    for (int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        g.push_back({a,b,w});
    }
    for (int lp = 0; lp < n; lp++) {
        for (auto & x : g) {
            int a = x[0];
            int b = x[1];
            int w = x[2];
            if (dist[a] != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
        }
    }
    cout << dist[v];
}