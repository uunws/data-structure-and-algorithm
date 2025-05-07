#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> k;
vector<int> ans;
vector<int> k1;
int max_idx = 7;
int min_idx = 0;
unordered_map<int,vector<int>> m1;
vector<int> maxedge;

bool all_yes() {
    for (auto & x : ans) {
        if (x==0) return false;
    }
    return true;
}

void recur(int node, int sum, vector<int> &vst, int h, int parent, bool cycle) {
    // if (k1[min_idx] == k1[max_idx]) return;
    if (cycle) {
        for (int i = 0; i < 8 ;i++) {
            if (ans[i] == 1 || ans[i] == -1) continue;
            if (sum == k[i]) {
                // cout << sum << endl;
                ans[i] = -1;
            }
        }
    }
    if (all_yes()) return;
    if (sum > k1[max_idx]) return;
    if (sum + h < k1[min_idx]) return;
    for (int i = 0; i < 8; i++) {
        if (ans[i] == 1 || ans[i] == -1) continue;
        if (sum == k[i]) {
            ans[i] = 1;
        }
    }
    vst[node] = 1;
    for (int i = 0; i < n; i++) {
        if (g[node][i] == -1) continue;
        if (vst[i] == 0) {
            vst[i] = 1;
            recur(i,sum+g[node][i],vst,h-maxedge[i],node, false);
            vst[i] = 0;
        } else {
            if (i != parent) {
                // cout << parent << "->" << i << endl;
                // recur(i,sum+g[node][i],vst,h-maxedge[i],node,true);
            }
        }
    }
    vst[node] = 0;
}

int main() {
    cin >> n >> m;
    k.assign(8,0);
    for (int i = 0; i < 8; i++) {
        cin >> k[i];
        m1[k[i]].push_back(i);
    }

    // for (auto & x : m1) {
    //     cout << x.first << ":";
    //     for (auto & y : x.second) cout << y << " ";
    // }
    // cout << "done m1" << endl;

    k1 = k;
    sort(k1.begin(),k1.end());
    g.assign(n,vector<int>(n,-1));
    maxedge.assign(n,0);
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
        maxedge[a] = max(maxedge[a],c);
        maxedge[b] = max(maxedge[b],c);
    }
    int sum_maxedge = accumulate(maxedge.begin(),maxedge.end(),0);
    ans.assign(8,0);
    for (int i = 0; i < n; i++) {
        vector<int> vst(n,0);
        recur(i,0,vst,sum_maxedge-maxedge[i],-1,false);
    }
    for (auto & x : ans) {
        if (x==0 || x==-1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
