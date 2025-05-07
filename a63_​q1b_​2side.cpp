#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recur(int i, int state, int w, vector<int> &l, vector<int> &r, vector<vector<int>> table) {
    if (i <= 0) {
        return 0;
    }
    if (table[i][state] != -2) {
        return table[i][state];
    }
    int res = max(recur(i-1, state, w, l, r, table), recur(i-w-1, !state, w, l, r, table) + ((state)? r[i] : l[i]));
    table[i][state] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, k;
    cin >> n >> w >> k;
    vector<int> l(n+1); // assign start at 1
    vector<int> r(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    // left : 0 right : 1 (state)
    // ans = max(f(n, 0), f(n, 1))
    // f(i, 0) = max(f(i-1, 0), f(i-w-1, 1)+l[i])
    vector<vector<int>> table(n+2, vector<int> (2, -2));
    cout << max(recur(n, 0, w, l, r, table), recur(n, 1, w, l, r, table));
    // vector<vector<int>> dp(n+1, vector<int> (2));
    // dp[0][0] = 0;
    // dp[0][1] = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (i-w-1<0) {
    //         dp[i][0] = max(dp[i-1][0], r[i]);
    //         dp[i][1] = max(dp[i-1][1], l[i]);
    //     } else {
    //         dp[i][0] = max(dp[i-1][0], dp[i-w-1][1] + l[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-w-1][0] + r[i]);
    //     }
    // }
    // // debug
    // for (auto &x : dp) {
    //     for (auto &y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << max(dp[n][0], dp[n][1]);
}