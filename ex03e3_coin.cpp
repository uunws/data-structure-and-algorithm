#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> D(n); // D = {10, 5, 2, 1} decrease order
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }
    // n : row, m : column (wanted value)
    vector<vector<int>> arr(n+1, vector<int>(m+1, 1000000));
    for (int i = 0; i <= n; i++) {
        arr[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        arr[0][i] = 1000000; // no coin -> sum of coin is impossible
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            if (D[a-1] > b) { // ตกขอบ
                arr[a][b] = arr[a-1][b];
            } else {
                arr[a][b] = min(arr[a][b-D[a-1]]+1, arr[a-1][b]); // why + 1 : adding one more coin
            }
        }
    }
    // // debug
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << arr[n][m];
}