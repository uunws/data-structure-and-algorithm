#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m = 10000007;
    int n, k;
    cin >> n >> k;
    vector<int> dp(n+1); //0...n
    dp[0] = 0;
    dp[1] = 2; // ใส่ได้ 0,1
    for(int i = 2; i <= n; i++) {
        if (i-k>0) {
            dp[i] = dp[i-1]%m + dp[i-k]%m;
        } else {
            dp[i] = dp[i-1]%m + 1;
        }
    }
    cout << dp[n]%m;
}