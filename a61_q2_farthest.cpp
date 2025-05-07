#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<int> dist;

int main() {
    cin >> n;
    matrix.assign(n+1, vector<int> (n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    dist.assign(n+1,INT_MAX);
    dist[1] = 0; // start at city 1
    for (int i = 1; i < n; i++) {
        for (int a = 1; a <= n; a++) { // ไล่ทุกเส้นเชื่อม
            for (int b = 1; b <= n; b++) {
                if (a != b && matrix[a][b] != -1) { // มีเส้นเชื่อมนั้นจริงๆ
                    if (dist[a] != INT_MAX && dist[b] > dist[a] + matrix[a][b]) {
                        dist[b] = dist[a] + matrix[a][b];
                    }
                }
            }
        }
    }
    // //
    // for (auto & x : dist) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // //
    int ans_max = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "-1";
            return 0;
        }
        ans_max = max(ans_max, dist[i]);
    }
    cout << ans_max;
}