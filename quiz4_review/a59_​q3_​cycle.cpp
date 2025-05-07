#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int> from;
void dfs(int node, map<int,vector<int>> &g, vector<int> &vst, int parent) {
    vst[node] = 1;
    for (auto & b : g[node]) {
        if (vst[b] == 0) {
            vst[b] = 1;
            dfs(b,g,vst,node);
        } else if (b != parent) {
            return;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    map<int,vector<int>> g;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vst(n,0);
    dfs(0,g,vst,-1,1);
    cout << ans;
}