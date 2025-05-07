#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>
using namespace std;

int dfs(vector<vector<int>> &adj, int x, vector<int> &b) {
    int res = b[x]; // เก็บค่าตัวมันเองไว้ก่อน
    b[x] = 0; // ล้างค่าที่ไหม้ให้กลายเปน0ให้หมด
    for (auto & i : adj[x]) {
        if (b[i]!= 0) res += dfs(adj, i, b); // บวกค่าทั้งหมดที่ืnodeนั้นครอบคลุม(โยงไปถึงได้)
        // reduce recursion loop (0 has no effect in value)
        // แก้ปุ๊ป100เลย
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }
    vector<int> q(k);
    for (int i = 0; i < k; i++) {
        cin >> q[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (auto & x : q) {
        sum = sum - dfs(adj, x, b); // sumที่เหลือคือ sumที่จะเอาไปใช้ต่อ
        cout << sum << " ";
    }
}
