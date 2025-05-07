#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

int n;
int t1,t2,t3;
queue<int> q;
vector<vector<int>> dist; // [from t1,t2,t3][minimun dist]

int main() {
    cin >> n;
    cin >> t1 >> t2 >> t3;
    vector<int> T = {t1,t2,t3};
    vector<vector<int>> e(n+1);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            e[i+1].push_back(x); // i+1->x (ปลายทางจากi+1)
        }
    }
    dist.assign(3, vector<int>(n+1,INT_MAX)); // assign initial as INT_MAX
    for (int i = 0; i < 3; i++) {
        q.push(T[i]);
        dist[i][T[i]] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto & b : e[u]) {
                if (dist[i][u] + 1 < dist[i][b]) { // select minimum
                    dist[i][b] = dist[i][u] + 1;
                    q.push(b); // push neighbor
                }
            }
        }
    }
    int ans = INT_MAX; // initial ans as INT_MAX
    for (int i = 0; i <= n; i++) {
        int res;
        if (dist[0][i] == INT_MAX || dist[1][i] == INT_MAX || dist[2][i] == INT_MAX) {
            continue; // if some of them dont have value (did not been consider) -> dont consider that round (all of them)
        } else { 
            res = max({dist[0][i], dist[1][i], dist[2][i]}); // max from t1,t2,t3
        }
        if (res < ans) ans = res; // most min that can be
    }
    cout << ans;
}