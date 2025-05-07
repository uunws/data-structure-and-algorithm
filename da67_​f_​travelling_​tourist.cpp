#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> ans;

void permu(int k, vector<int> &sol, int len, vector<int> &vst, vector<int> &s) {
    if (len == k) {
        ans.push_back(sol);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (vst[i] == 0) {
            vst[i] = 1;
            sol.push_back(s[i]);
            permu(k,sol,len+1,vst,s);
            vst[i] = 0;
            sol.pop_back(); // dont forget to pop_back
        }
    }
}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
        s[i]--;
    }
    vector<vector<int>> g(n, vector<int> (n,-1));
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
        g[b][a] = c;
    }
    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j) dist[i][j] = 0;
            if (g[i][j] != -1 && i != j) dist[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // now that we have every pair shortest path
    // find which order of k node we gonna visit
    // using permu
    vector<int> vst(k,0);
    vector<int> sol;
    permu(k,sol,0,vst,s);
    int res = INT_MAX;
    for (auto & subvec : ans) {
        int d = 0;
        for (int i = 0; i < subvec.size()-1; i++) {
            int x1 = subvec[i];
            int x2 = subvec[i+1];
            d += dist[x1][x2];
        }
        res = min(res, d);
    }
    cout << res;
}