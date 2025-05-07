#include <iostream>
#include <vector>
using namespace std;
void recur(int a, int k, vector<vector<int>> &g, int h, vector<int> &visited, int &cnt) {
    if (h>k) return;
    if (visited[a] == 0) cnt++;
    visited[a] = 1;
    for (auto & x : g[a]) recur(x, k, g, h+1, visited, cnt);
}

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> g(n);
    for (int i=0; i<e; i++) {
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) { // startpoint
        cnt = 0; //reset cnt
        vector<int> visited(n, 0); //reset vector
        recur(i, k, g, 0, visited, cnt);
        if(cnt > ans) ans = cnt;
    }
    cout << ans;
}