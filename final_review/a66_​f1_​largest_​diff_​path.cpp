#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) { // start node
        stack<pair<int,int>> tmp;
        tmp.push({i,c[i]});
        vector<int> vst(n,0);
        vst[i] = 1;
        while (!tmp.empty()) {
            auto curr = tmp.top();
            tmp.pop();
            int node = curr.first;
            int curr_min = curr.second;
            for (auto & b : g[node]) {
                if (vst[b] == 0) {
                    vst[b] = 1;
                    tmp.push({b,min(c[b],curr_min)});
                    if (c[b]-curr_min > ans) ans = c[b] - curr_min;
                }
            }
        }
    }
    cout << max(0,ans);
}