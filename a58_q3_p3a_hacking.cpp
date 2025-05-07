#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <queue>
using namespace std;

int n,m,k;
vector<int> start;
vector<int> c;
map<int, vector<int>> adj;
vector<int> dist;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    cin >> n >> m >> k;
    start.assign(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> start[i];
    }
    c.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist.assign(n, INT_MAX);
    for (auto & st : start) {
        pq.push({c[st], st});
    }
    vector<int> visited(n, 0);
    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int time = curr.first;
        int node = curr.second;
        visited[node] = 1;
        // if (time > dist[node]) continue; // if time is old time -> skip (because we did not delete old time)
        for (auto & v : adj[node]) {
            if (visited[v] == 0) {
                if (dist[v] > time + c[v]) {
                    dist[v] = time + c[v];
                    pq.push({dist[v], v});
                }
            }
        }
    }
    int ans_max = 0;
    for (auto & x : dist) {
        // cout << x << " "; //
        if (x == INT_MAX) continue;
        ans_max = max(ans_max, x);
    }
    // cout << endl; //
    cout << ans_max;
}