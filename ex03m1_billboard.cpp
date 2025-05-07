#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> c(n); 
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> dp(n); // 0-base
    dp[0] = c[0];
    dp[1] = max(c[0], c[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-2] + c[i], dp[i-1]);
    }
    // // debug
    // for (auto & x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // //
    cout << dp[n-1];
}