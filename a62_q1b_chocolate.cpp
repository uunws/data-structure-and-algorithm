#include <iostream>
#include <vector>
using namespace std;

int m = 1000003;

// int recur(int res, vector<int> &s, vector<int> table) {
//     if (res == 0) {
//         return 1;
//     }
//     if (table[res] != -2) {
//         return table[res];
//     }
//     int sum = 0;
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] <= res) {
//             sum += recur(res-s[i], s, table)%m;
//         }
//     }
//     table[res] = sum%m;
//     return sum%m;
// }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    // vector<int> table(n+2, -2);
    // cout << recur(n, s, table);
    vector<int> dp(n+1); // dp(i) = recur(i)
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] <= i) {
                sum+=dp[i-s[j]]%m;
            }
        }
        dp[i] = sum%m;
    }
    cout << dp[n];
}