#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int recur(vector<vector<int>> &v, int h, int c, int len) {
//     if (h == len) { // leaves
//         return v[h][c];
//     } else {
//         return v[h][c] + max(recur(v, h+1, c, len), recur(v, h+1, c+1, len));
//     }
// }

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }
    // cout << recur(v, 0, 0, n-1);
    vector<vector<int>> dp(n, vector<int> (n));
    dp[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = v[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    // // debug
    // for (auto & x : dp) {
    //     for (auto & y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << dp[0][0]; 
}