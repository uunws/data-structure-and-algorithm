#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) { // 0-base
        cin >> p[i];
    }
    vector<int> dp(n+1, 1000000000); // find min, assign to max
    dp[0] = 0;
    for (int i = 1; i <= n; i++) { // 1-base
        int left = max(1, i-k); // check out of bound
        int right = min(n, i+k);
        int min_cost = p[i-1] + dp[left-1]; // min cost ตั้งแต่ left->right
        for (int j = left; j <= right; j++) {
            dp[j] = min(min_cost, dp[j]);  // เลือกว่าจะใช้ min cost ไหม
        }
    }
    cout << dp[n];
}