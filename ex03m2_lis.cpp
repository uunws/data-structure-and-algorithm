#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> sort_v(n);
    sort_v = v;
    sort(sort_v.begin(), sort_v.end());
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) { // row (sorted A)
        for (int j = 1; j <= n; j++) { // column (A)
            if (v[j-1] == sort_v[i-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    // // debug
    // for (auto &x : arr) {
    //     for (auto &y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << arr[n][n];
}