#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,m,k;
int v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    cin >> v;
    vector<int> dist(n, INT_MAX);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dist[x] = 0;
    }
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adj.push_back({a,b,w});
    }
    for (int i = 0; i < n; i++) {
        for (auto & p : adj) {
            int a = p[0];
            int b = p[1];
            int w = p[2];
            if (dist[a] != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
        }
    }
    cout << dist[v];
}