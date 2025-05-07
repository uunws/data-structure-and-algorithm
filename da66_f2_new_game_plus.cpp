#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m = 100000007;
    int r, c;
    cin >> r >> c;
    // เก็บสถานะห้อง
    // เก็บตัวที่เดินล่าสุด
    // เก็บ current door
    vector<vector<int>> status(r, vector<int> (c)); // 0,1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> status[i][j];
        }
    }
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (3, 0)));
    // idx0 : x  idx1 : y  idx2 : z
    for (int i = 0; i < r; i++) {
        if (!status[i][0]) {
            dp[i][0][0] = 1; // จุดเริ่มต้น
            dp[i][0][1] = 1;
            dp[i][0][2] = 1; 
        } 
    }
    for (int j = 1; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (!status[i][j]) {
                // door x
                if (i+1 < r && j-1 >= 0) {
                    dp[i][j][0] = dp[i+1][j-1][1]%m + dp[i+1][j-1][2]%m;
                }
                // door y
                if (j-1 >= 0) {
                    dp[i][j][1] = dp[i][j-1][0]%m + dp[i][j-1][2]%m;
                }
                // door z
                if (i-1 >= 0 && j-1 >= 0) {
                    dp[i][j][2] = dp[i-1][j-1][0]%m + dp[i-1][j-1][1]%m;
                }
            } else {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        ans = ans%m + dp[i][c-1][0]%m + dp[i][c-1][1]%m + dp[i][c-1][2]%m;
    }
    // // debug
    // for (auto &x : dp) {
    //     for (auto &y : x) {
    //         for (auto &z : y) {
    //             cout << z << " ";
    //         }
    //         cout << " || ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << (ans/2)%m;
}