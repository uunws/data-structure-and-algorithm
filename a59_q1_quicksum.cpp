#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    // find prefix_sum
    vector<vector<int>> p(n, vector<int>(m));
    p[0][0] = A[0][0];
    for (int j = 1; j < m; j++) {
        p[0][j] = p[0][j-1] + A[0][j];
    }
    for (int i = 1; i < n; i++) {
        p[i][0] = p[i-1][0] + A[i][0];
        for (int j = 1; j < m; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == 0 && c1 == 0) {
            // cout << p[r2][c2];
            ans[i] = p[r2][c2];
        } else if (c1 == 0) {
            // cout << p[r2][c2] - p[r1-1][c2];
            ans[i] = p[r2][c2] - p[r1-1][c2];
        } else if (r1 == 0) {
            // cout << p[r2][c2] - p[r2][c1-1];
            ans[i] = p[r2][c2] - p[r2][c1-1];
        } else {
            // cout << p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1];
            ans[i] = p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1];
        }
    }
    for (auto & x : ans) {
        cout << x << endl;
    }
}