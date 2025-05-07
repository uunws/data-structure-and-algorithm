// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int n,m;
// vector<int> co;
// vector<int> ci;
// vector<int> dist;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     cin >> n >> m;
//     ci.assign(n, 0);
//     for (int i = 0; i < n; i++) {
//         cin >> ci[i];
//     }
//     co.assign(n, 0);
//     for (int i = 0; i < n; i++) {
//         cin >> co[i];
//     }
//     vector<pair<int, int>> edges(m);
//     for (int i = 0; i < m; i++) { // edges ->
//         int a,b;
//         cin >> a >> b;
//         edges[i] = {a,b};
//     }
//     dist.assign(n, INT_MAX);
//     dist[0] = 0; // start at 0
//     for (int i = 1; i < n; i++) {
//         for (auto & p : edges) {
//             int a = p.first;
//             int b = p.second;
//             if (dist[a] != INT_MAX && dist[b] > dist[a] + co[a] + ci[b]) {
//                 dist[b] = dist[a] + co[a] + ci[b];
//             }
//         }
//     }
//     for (auto & x : dist) {
//         if (x == INT_MAX) { 
//             // ถ้าเป็น INT_MAX แสดงว่า จากจุดstartไม่สามารถไปถึงได้ ไม่ว่าจะใช้pathทั้งหมด
//             cout << "-1 "; 
//         } else {
//             cout << x << " ";
//         }
//     }
// }

// use dijkstra because it better at runtime than bellman
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ci(n);
    for (int i = 0; i < n; i++) {
        cin >> ci[i];
    }
    vector<int> co(n);
    for (int i = 0; i < n; i++) {
        cin >> co[i];
    }
    map<int, vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int time = p.first;
        int node = p.second;
        if (time > dist[node]) continue; // ignore the information that time is more that store value in dist vector
        for (auto & v : adj[node]) {
            if (dist[v] > time + ci[v] + co[node]) {
                // pq.remove({dist[v], v}); // dont have to remove, we have constrain that skip old information
                // pq does not have remove, have only pop
                dist[v] = time + ci[v] + co[node];
                pq.push({dist[v], v});
            }
        }
    }
    for (auto & x : dist) {
        if (x == INT_MAX) { 
            // ถ้าเป็น INT_MAX แสดงว่า จากจุดstartไม่สามารถไปถึงได้ ไม่ว่าจะใช้pathทั้งหมด
            cout << "-1 "; 
        } else {
            cout << x << " ";
        }
    }
}