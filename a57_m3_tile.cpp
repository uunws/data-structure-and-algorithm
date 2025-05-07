#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

        }
    }
}