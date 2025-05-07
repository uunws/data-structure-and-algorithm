#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> dp(n);
    dp[0] = c[0];
    dp[1] = max(c[0], c[1]);
    dp[2] = max({c[0], c[1], c[2]});
    int res = max({c[0], c[1], c[2]});
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-3] + c[i], res);
        res = max(res, dp[i]);
    }
    // // debug
    // for (auto & x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // //
    cout << dp[n-1];
}