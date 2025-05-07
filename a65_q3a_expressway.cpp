#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> c;
vector<vector<int>> dist;

int main() {
    int x;
    cin >> n >> x;
    c.assign(n+1, vector<int> (n+1, 1000000)); // if 100000 just get 50%
    // c also have to be initialize as INT_MAX
    // because there is some (a,b) that does not have edge and we want it to be infinity
    c[1][2] = x;
    c[2][1] = x; // undirected
    for (int i = 3; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int t,p;
            cin >> t >> p;
            c[i][t] = p;
            c[t][i] = p;
        }
    }
    dist.assign(n+1, vector<int> (n+1, 1000000));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = c[i][j];
            }
        }
    }
    dist[1][2] = c[1][2];
    dist[2][1] = c[2][1];
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // if (i == 1 && j == 2) {
                //     cout << dist[i][k] << " " << dist[k][j] << endl;
                // }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        // for (auto & x : dist) {
        //     for (auto & y : x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        if (k != 1 && k != 2) {
            cout << dist[1][2] << " ";
        }
        // cout << endl;
    }
}