#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m,k;
vector<int> b;
vector<int> fire;
// map<int, vector<int>> adj;
int sum;

int dfs(int a, vector<vector<int>> &adj) {
    int res = b[a];
    b[a] = 0;
    for (auto & x : adj[a]) {
        if (b[x] != 0) {
            res += dfs(x, adj);
        }
    }
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    b.assign(n, 0);
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }
    fire.assign(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> fire[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (auto & x : fire) {
        sum = sum - dfs(x, adj);
        cout << sum << " ";
    }
}