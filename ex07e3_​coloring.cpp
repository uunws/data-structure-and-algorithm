#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n,e;

int color(vector<vector<int>> &g, set<pair<int,int>, greater<pair<int,int>>> °) {
    vector<int> color(n,-1); // color of each node
    auto first = *(deg.begin());
    int first_node = first.second;
    color[first_node] = 1; // color first node (0) to 1
    // find that the color that can not be (the color that neighbor already be)
    for (auto it = deg.begin(); it != deg.end(); it++) { // check each node
        // if (it == deg.begin()) continue;
        auto curr = *it;
        int node = curr.second;
        vector<bool> mark(n+1, false); // each color status
        for (auto & b : g[node]) {
            if (color[b] != -1) mark[color[b]] = true;
        }
        int idx = 1;
        while (idx <= n) {
            if (!mark[idx]) break;
            idx++;
        }
        color[node] = idx;
    }
    // for (auto & x : color) cout << x << " ";
    // cout << endl;
    return *max_element(color.begin(),color.end());
}

int main() {
    cin >> n >> e;
    vector<vector<int>> g(n);
    set<pair<int,int>, greater<pair<int,int>>> deg; // deg,node
    for (int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        deg.insert({g[i].size(), i});
    }
    cout << color(g, deg);
}
