#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

// this problem is strong connected component (direct, reachable in both ways)
// Kosaraju’s Algorithm (2 * dfs)
// *dfs* *use stack*

int n;
stack<int> s;

void dfs1(int a, vector<int> &vst1, vector<vector<int>> &adj) { // fill topological order stack
    vst1[a] = 1;
    for (auto & b : adj[a]) {
        if (vst1[b] == 0) {
            dfs1(b, vst1, adj);
        }
    }
    s.push(a); // push ตัวที่ไปตันก่อน
}

void dfs2(int a, vector<int> &vst2, int &size, vector<vector<int>> &adj_re) {
    vst2[a] = 1;
    size++; // add size
    for (auto & b : adj_re[a]) {
        if (vst2[b] == 0) {
            dfs2(b, vst2, size, adj_re);
        }
    }
}

int main() {
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> adj_re(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int a;
            cin >> a;
            adj[i].push_back(a);
            adj_re[a].push_back(i);
        }
    }
    vector<int> vst1(n, 0);
    for (int i = 0; i < n; i++) {
        if (vst1[i] == 0) {
            dfs1(i, vst1, adj);
        }
    }
    vector<int> vst2(n, 0);
    vector<int> ans; // set คำตอบ
    while (!s.empty()) { // second dfs is in order of topo
        int curr = s.top(); s.pop();
        if (vst2[curr] == 0) {
            int size = 0;
            dfs2(curr, vst2, size, adj_re); // 1 recur จนจบ = 1 connected component
            ans.push_back(size);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto & x : ans) {
        cout << x << " ";
    }
}