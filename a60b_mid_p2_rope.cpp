#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, -1); // initialize to -1, ถ้าเป็น -1 แสดงว่า array นั้น ยังไม่มีค่า ยังไม่ต้อง check
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= a && dp[i-a] != -1) dp[i] = max(dp[i], dp[i-a]+1); // dp[i-a] + 1 ก็คือ เลือกที่จะตัดเป็นความยาว a เลยเพิ่มจำนวนท่อนมา1
        if (i >= b && dp[i-b] != -1) dp[i] = max(dp[i], dp[i-b]+1); // dp[i] ข้างหน้า ก็คือ ผ่านการเช็คของ a มาแล้ว
        if (i >= c && dp[i-c] != -1) dp[i] = max(dp[i], dp[i-c]+1);
        // dp[i] = max({(i<a)? -1 : dp[i-a], (i<b)? -1 : dp[i-b], (i<c)? -1 : dp[i-c]}) + 1;
    }
    // // debug
    // for (auto & x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // //
    cout << dp[n];
}