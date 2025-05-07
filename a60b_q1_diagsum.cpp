#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) { // row
        for (int j = 0; j < n; j++) { // column
            cin >> v[i][j];
        }
    }
    int num_max = -10000000;
    for (int j = 0; j < n; j++) { // บน diagonal
        // เริ่ม chain (0,0) (0,1) -> (0,n)
        // chain (0,0) -> (1,1) -> (2,2)
        // chain (0,1) -> (1,2) -> (2,3)
        int x = 0; int y = j;
        int maxEnd = v[x][y];
        int res = v[x][y];
        for (int p = 1; p < n - j && x+p < n && y+p < n; p++) {
            maxEnd = max(maxEnd + v[x+p][y+p], v[x+p][y+p]);
            res = max(maxEnd, res);
        }
        num_max = max(num_max, res);
    }
    for (int i = 0; i < n; i++) { // ล่าง diagonal
        int x = i; int y = 0;
        int maxEnd = v[x][y];
        int res = v[x][y];
        for (int p = 1; p < n - i && x+p < n && y+p < n; p++) {
            maxEnd = max(maxEnd + v[x+p][y+p], v[x+p][y+p]);
            res = max(maxEnd, res);
        }
        num_max = max(num_max, res);
    }
    cout << num_max;
    // int num_max = -10000000;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 1; k <= n; k++) {
    //             // find max
    //             int res = 0;
    //             for (int p = 0; p < k && i+p<n && j+p<n; p++) {
    //                 res += v[i+p][j+p];
    //             }
    //             num_max = max(num_max, res);
    //         }
    //     }
    // }
    // cout << num_max;
}