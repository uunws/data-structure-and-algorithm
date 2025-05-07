#include <iostream>
#include <vector>
using namespace std;

int dp[2][32][32]; // initialize i to 2 state because it only need that state and previous state
// 2 -> (optimization)

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    dp[1][1][0] = 1; // initialize 1 line, end with black, m=1, k=0
    for (int i = 2; i <= n; i++) { 
        for (int j = 1; j <= m; j++) { // reset table for every i
            for (int l = 0; l <= k; l++) {
                dp[i%2][j][l] = 0;
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                dp[i%2][j+1][l] += dp[(i-1)%2][j][l]; // same bit
                dp[i%2][1][l+1] += dp[(i-1)%2][j][l]; // cahnge bit
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans += dp[n%2][j][k]; // exactly n number k color change of all m
    }
    cout << ans;
}