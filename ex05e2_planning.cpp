#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        indeg[i] = m; // in deg (ลูกศรโยงมาหา i)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[x].push_back(i); // x โยงไปหา i 
        }
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++) { 
        if (indeg[i] == 0) { // can be starting point
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (auto & x : adj[u]) {
            indeg[x]--; // ลบเส้นที่โยงจาก u (indeg ของ x)
            if (indeg[x] == 0) { // can be starting point
                q.push(x);
            }
        }
    }
    for (auto & x : ans) {
        cout << x << " ";
    }
}