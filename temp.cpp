#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int n;

vector<vector<int>> g;
vector<int> pf;

int ans = INT_MIN;
void dfs(int node, int len, int hp, vector<int> &vst) {
    if (node == n-1 && len == n) {
        ans = max(ans, hp);
        return;
    }
    if (len == n) return;
    if (node == n-1 && len < n) return;
    // heur + hp < ans -> cannot me maximum value
    int h = pf[n-1-len];
    if (h + hp < ans) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vst[i] == 1) continue;
        if (i == node) continue;
        vst[i] = 1;
        dfs(i, len+1, hp+g[node][i], vst);
        vst[i] = 0;
    }
}

int main() {
    cin >> n;
    g.assign(n, vector<int> (n,0));
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            res.push_back(g[i][j]);
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(),res.end());
    pf.assign(n-1,0); // index = number of edge left
    pf[0] = res[0];
    for (int i = 1; i < n; i++) {
        pf[i] = pf[i-1] + res[i];
    }
    vector<int> vst(n, 0);
    vst[0] = 1;
    dfs(0,1,0,vst); // len start at 1 (include first 0)
    cout << ans;
}

// after normal dfs, we have to improve runtime
// backtrack
// branch and bound