#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int> (m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    if (n==1) {
        int ans = 0;
        for (auto & x : v[1]) {
            ans += x;
        }
        cout << ans;
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    dp[1][1] = v[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i-1][1] + v[i][1], v[i][1]);
    }
    for (int j = 2; j <= m; j++) {
        dp[1][j] = max(dp[1][j-1] + v[1][j], v[1][j]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = max({dp[i-1][j]+v[i][j], dp[i][j-1]+v[i][j], dp[i-1][j-1]+v[i][j]*2, v[i][j]});
        }
    }
    // // debug
    // cout << "-------" << endl;
    // for (auto &x : v) {
    //     for (auto &y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-------" << endl;
    // for (auto &x : dp) {
    //     for (auto &y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << dp[n][m];
}