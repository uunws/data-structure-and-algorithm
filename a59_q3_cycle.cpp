#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

pair<int, int> s;

void recur1(int a, map<int, set<int>> &adj, vector<int> &visited, int parent, vector<int> &from) {
    visited[a] = 1;
    for (auto & b : adj[a]) {
        if (visited[b] == 0) {
            from[b] = a;
            recur1(b, adj, visited, a, from);
        } else if (b != parent) {
            s = {b, a}; // 2 0
        }
    }
}

int findCycleSize(map<int, set<int>> &adj, vector<int> &from) {
    // จาก b ไล่ย้อนกลับไปโดย from จนเจอ a
    int cnt = 1;
    int p = s.first;
    while (p != s.second) {
        p = from[p];
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    map<int ,set<int>> adj;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> visited(n, 0);
    vector<int> from(n, -1);
    recur1(0, adj, visited, -1, from);
    cout << findCycleSize(adj, from);
}  