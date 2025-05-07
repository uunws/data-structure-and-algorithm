#include <bits/stdc++.h>

using namespace std;

int n,m;
int cc_num = 0;
map<int,int> color;
vector<int> ans; // store empty node

bool check() { // check is color correct from color
    for (auto & x : color) {
        int num = x.first;
        int col = x.second;
        if (num < n) { // has to be blue
            if (col == 0) return false;
        } else if (num < 2*n) { // has to be red
            if (col == 1) return false;
        }
    }
    return true;
}

bool recur(int node, vector<vector<int>> &g, int prev) {
    if (check()) {
        return true;
    }
    for (auto & b : g[node]) {
        if (b == prev) continue;
        ans.push_back(b);
        int color_node = color[node];
        int color_b = color[b];
        color[node] = color_b;
        color[b]= color_node;
        return recur(b, g, node);
    }
    return false;
}

void dfs(int node, vector<vector<int>> &g, vector<int> &vst) {
    vst[node] = cc_num;
    for (auto & b : g[node]) {
        if (b == 2*n) continue;
        if (vst[b] == 0) {
            dfs(b,g,vst);
        }
    }
} 

int main() {
    cin >> n >> m;
    vector<vector<int>> g(30);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vst(2*n,0);
    for (int i = 0; i < 2*n; i++) {
        if (vst[i] == 0) {
            cc_num += 1;
            dfs(i,g,vst);
        }
    }
    // cout << "cc_num" << cc_num << endl; 
    // if (cc_num > 1) {
    //     cout << "-1";
    //     return 0;
    // }
    // assign map
    for (int i = 0; i <= 2*n; i++) {
        if (i < n) {
            color[i] = 0; // red
        } else if (i < 2*n) {
            color[i] = 1; // blue
        } else {
            color[i] = 2;
        }
    }
    if (recur(2*n,g,-1)) {
        cout << ans.size() << endl;
        for (auto & x : ans) {
            cout << x+1 << " ";
        }
    } else {
        cout << "-1" << endl;
    }
    
}