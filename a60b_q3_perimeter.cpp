#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,e,k;
queue<pair<int, int>> q;
int vst[1001];

int main() {
    cin >> n >> e >> k;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    q.push({0, 0});
    vst[0] = 1;
    int cnt = 0;
    while (!q.empty()) {
        auto u = q.front();
        int x = u.first;
        int w = u.second;
        q.pop();
        if (w == k) cnt++;
        if (w>k) continue;
        for (auto & b : g[x]) {
            if (vst[b] == 0) {
                vst[b] = 1;
                q.push({b, w+1});
            }
        }
    }
    cout << cnt;
}